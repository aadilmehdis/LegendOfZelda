#include "volcano.h"
#include "main.h"
#include "shapes.h"

Volcano::Volcano(glm::vec3 origin) {
    // this->position = glm::vec3(x, -11, 0);
    this->position = origin;
    this->rotation = 0;
    speed = 1;

	float z_pullBack = 5;

	// std::vector<GLfloat> vertex_buffer = makePrism(10,1, 10, false,0,0, 0 + z_pullBack);
	// std::vector<GLfloat> vertex_buffer2 = makeFrustum(10, 1, 0.6, 1, false,0,0, -10 + z_pullBack);
	// std::vector<GLfloat> vertex_buffer3 = makeFrustum(10,0.8,1,0.8,true,0,0,0.8 + z_pullBack);
	// std::vector<GLfloat> vertex_buffer4 = makePrism(10,0.6, 2, true,2.5,0, -5.5 + z_pullBack);
	// std::vector<GLfloat> vertex_buffer5 = makePrism(10,0.6, 2, true,-2.5,0, -5.5 + z_pullBack);

    std::vector<GLfloat> vertex_buffer = makeFrustum(20, 15, 10, 6, true, 0, 0, 0);
    std::vector<GLfloat> vertex_buffer2 = makeFrustum(20, 8, 5, 6, true, 0, 0, -6);
    std::vector<GLfloat> vertex_buffer3 = makeFrustum(20, 4, 3, 4, true, 0, 0, -12);
    std::vector<GLfloat> vertex_buffer4 = makePrism(20, 2, 2,true,0,0,-16);

	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());

    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_DARK_BROWN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, vertex_buffer2.size()/3, vertex_buffer2.data(), COLOR_BROWN, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, vertex_buffer4.size()/3, vertex_buffer4.data(), COLOR_LAVA, GL_FILL);
}

void Volcano::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (90 * M_PI / 180.0f), glm::vec3(1, 0, 0));

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}


void Volcano::tick() {
}
