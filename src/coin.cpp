#include "coin.h"
#include "main.h"
#include "shapes.h"

Coin::Coin(glm::vec3 origin) {
    this->position = origin;
    this->rotation = 0;
    this->current = false;
    this->radius = 5;

	float z_pullBack = 5;

    std::vector<GLfloat> vertex_buffer = makePrism(20, 10, 3, true, 0, 0, 0);

    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_JET_WING, GL_FILL);
    this->object2 = create3DObject(GL_LINES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_JET_BODY, GL_LINE);
}

void Coin::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 rotate1    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1,0,0));
    Matrices.model *= (translate * rotate1);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}


void Coin::tick() {
}