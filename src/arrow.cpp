#include "arrow.h"
#include "main.h"
#include "shapes.h"

Arrow::Arrow(glm::vec3 origin) {
    this->position = origin;
    this->rotation = 0;

	float z_pullBack = 5;

    std::vector<GLfloat> vertex_buffer = makeFrustum(4, 2, 1, 10, true, 0, 0, 0);
    std::vector<GLfloat> vertex_buffer1 = makePyramid(15, 2, 5, true,0,0,-10);
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer1.begin(), vertex_buffer1.end());

    for(int i=0;i<vertex_buffer.size();++i)
    {
        vertex_buffer[i] *= 4;
    }



    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_LAVA, GL_LINE);
}

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 rotate1    = glm::rotate((float) (-90 * M_PI / 180.0f), glm::vec3(1,0,0));
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1,0));
    Matrices.model *= (translate * rotate * rotate1);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}


void Arrow::tick() {
    this->rotation += 1;
}