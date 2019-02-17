#include "arrow.h"
#include "main.h"
#include "shapes.h"

Arrow::Arrow(glm::vec3 origin) {
    this->position = origin;
    this->rotation = 0;

	float z_pullBack = 5;

    std::vector<GLfloat> vertex_buffer = makeFrustum(4, 2, 1, 10, true, 0, 0, 0);

    vertex_buffer.push_back(2);
    vertex_buffer.push_back(-0.5);
    vertex_buffer.push_back(-9);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(-0.5);
    vertex_buffer.push_back(-10);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(-0.5);
    vertex_buffer.push_back(-11);

    vertex_buffer.push_back(-2);
    vertex_buffer.push_back(-0.5);
    vertex_buffer.push_back(-9);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(-0.5);
    vertex_buffer.push_back(-10);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(-0.5);
    vertex_buffer.push_back(-11);

    vertex_buffer.push_back(2);
    vertex_buffer.push_back(0.5);
    vertex_buffer.push_back(-9);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(0.5);
    vertex_buffer.push_back(-10);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(0.5);
    vertex_buffer.push_back(-11);

    vertex_buffer.push_back(-2);
    vertex_buffer.push_back(0.5);
    vertex_buffer.push_back(-9);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(0.5);
    vertex_buffer.push_back(-10);

    vertex_buffer.push_back(0);
    vertex_buffer.push_back(0.5);
    vertex_buffer.push_back(-11);

    


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_LAVA, GL_FILL);
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
