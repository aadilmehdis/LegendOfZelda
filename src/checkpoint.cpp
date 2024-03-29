#include "checkpoint.h"
#include "main.h"
#include "shapes.h"

CheckPoint::CheckPoint(glm::vec3 origin) {
    this->position = origin;
    this->current = false;
    this->destroyed = false;
    this->radius = 20;

	float z_pullBack = 8.8;
	float y_pullBack = 0;



    std::vector<GLfloat> vertex_buffer = makePrism(20,10,3,true,0,0+y_pullBack,0+z_pullBack);
    std::vector<GLfloat> vertex_buffer1 = makePrism(4,18,3,true,0,0+y_pullBack,3+z_pullBack);


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_BROWN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_LIGHT_BROWN, GL_LINE);
    this->object3 = create3DObject(GL_TRIANGLES, vertex_buffer1.size()/3, vertex_buffer1.data(), COLOR_NOIR, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, vertex_buffer1.size()/3, vertex_buffer1.data(), COLOR_SILVER, GL_LINE);

}

void CheckPoint::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 rotate    = glm::rotate((float) (90 * M_PI / 180.0f), glm::vec3(1,0,0));
    glm::mat4 rotate2    = glm::rotate((float) (45 * M_PI / 180.0f), glm::vec3(0,1,0));

    Matrices.model *= (translate * rotate2 * rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}


void CheckPoint::tick() {
}
