#include "missile.h"
#include "main.h"
#include "shapes.h"

Missile::Missile(glm::vec3 origin, glm::vec3 velocity, glm::mat4 rotate) {
    this->position = origin;
    this->velocity = velocity;
    this->rotation = 0;
    this->rotate = rotate;
    speed = 1;

	float z_pullBack = 5;

    // std::vector<GLfloat> vertex_buffer = makeFrustum(20, 15, 10, 6, true, 0, 0, 0);
    // std::vector<GLfloat> vertex_buffer2 = makeFrustum(20, 8, 5, 6, true, 0, 0, -6);
    // std::vector<GLfloat> vertex_buffer3 = makeFrustum(20, 4, 3, 4, true, 0, 0, -12);
    // std::vector<GLfloat> vertex_buffer4 = makePrism(20, 2, 2,true,0,0,-16);
    std::vector<GLfloat> vertex_buffer  = makeFrustum(20, 1.75, 2, 2, true, 0, 0, 0); 
    std::vector<GLfloat> vertex_buffer1  = makePrism(20, 2, 8, true, 0, 0, -2);
    std::vector<GLfloat> vertex_buffer2  = makeFrustum(20, 2, 1,4, true, 0, 0, -10);
    std::vector<GLfloat> vertex_buffer3  =  makePyramid(20, 1,10,false,0,0,-14);

	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer1.begin(), vertex_buffer1.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer2.begin(), vertex_buffer2.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());

    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(0.0f);

    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(6.0f);
    vertex_buffer.push_back(0.0f);

    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(-3.0f);

    for(int i=0;i<vertex_buffer.size();++i)
    {
        vertex_buffer[i] *= 0.6;
    }


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_DARK_BROWN, GL_LINE);
}

void Missile::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * this->rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    // draw3DObject(this->object2);
    // draw3DObject(this->object3);
}


void Missile::tick() {
    this->position  -= this->velocity;
}
