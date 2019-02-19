#include "compass.h"
#include "main.h"
#include "shapes.h"

Compass::Compass(glm::vec3 origin) {
    this->position = origin;
    this->rotate = rotate;
    this->rotation = 0;
    this->rotation_speed = 1;

	float z_pullBack = 5;

    std::vector<GLfloat> vertex_buffer = makeFrustum(100,0.5, 0.6,0,false,0,0,0);

    std::vector<GLfloat> vertex_buffer1;
    vertex_buffer1.push_back(-0.1f);
    vertex_buffer1.push_back(0.0f);
    vertex_buffer1.push_back(0.0f);

    vertex_buffer1.push_back(0.1f);
    vertex_buffer1.push_back(0.0f);
    vertex_buffer1.push_back(0.0f);

    vertex_buffer1.push_back(0.0f);
    vertex_buffer1.push_back(0.4f);
    vertex_buffer1.push_back(0.0f);


    std::vector<GLfloat> vertex_buffer2;
    vertex_buffer2.push_back(-0.1f);
    vertex_buffer2.push_back(0.0f);
    vertex_buffer2.push_back(0.0f);

    vertex_buffer2.push_back(0.1f);
    vertex_buffer2.push_back(0.0f);
    vertex_buffer2.push_back(0.0f);

    vertex_buffer2.push_back(0.0f);
    vertex_buffer2.push_back(-0.4f);
    vertex_buffer2.push_back(0.0f);


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_BLACK, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, vertex_buffer1.size()/3, vertex_buffer1.data(), COLOR_LAVA, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, vertex_buffer2.size()/3, vertex_buffer2.data(), COLOR_PRUSSIAN_BLUE, GL_FILL);

}

void Compass::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,0,1));

    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}


void Compass::tick() {
}
