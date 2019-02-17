#include "bomb.h"
#include "main.h"
#include "shapes.h"

Bomb::Bomb(glm::vec3 origin, glm::vec3 velocity, glm::mat4 rotate) {
    this->position = origin;
    this->rotate = rotate;
    this->gravity = glm::vec3(0,0.01,0);
    this->velocity = velocity;
    this->radius = 2.5;

	float z_pullBack = 5;

    std::vector<GLfloat> vertex_buffer = makeFrustum(20, 2, 1, 1.5, true, 0, 0, 0);
    std::vector<GLfloat> vertex_buffer1 = makeFrustum(20, 2, 2, 1.5, true, 0, 0, 1.5);
    std::vector<GLfloat> vertex_buffer2 = makeFrustum(20, 1, 2, 1.5, true, 0, 0, 3.0);
    std::vector<GLfloat> vertex_buffer3 = makeFrustum(20, 1.5, 1, 0.5, true, 0, 0, 3.5);

	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer1.begin(), vertex_buffer1.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer2.begin(), vertex_buffer2.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());

    // for(int i=0;i<vertex_buffer.size();++i)
    // {
    //     vertex_buffer[i] ;
    // }
    std::vector<GLfloat> vertex_buffer4;
    vertex_buffer4.push_back(0.0f);
    vertex_buffer4.push_back(0.0f);
    vertex_buffer4.push_back(0.0f);

    vertex_buffer4.push_back(this->radius);
    vertex_buffer4.push_back(0.0f);
    vertex_buffer4.push_back(0.0f);


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_DARK_BROWN, GL_LINE);
    this->object2 = create3DObject(GL_LINES, vertex_buffer4.size()/3, vertex_buffer4.data(), COLOR_RED, GL_FILL);
}

void Bomb::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * this->rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}


void Bomb::tick() {
    this->velocity += this->gravity;
    this->position -= this->velocity;
}
