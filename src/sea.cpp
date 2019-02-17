#include "sea.h"
#include "main.h"

Sea::Sea(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);

    this->rotation = 0;
    speed = 1;

    float height = -10;

	std::vector<GLfloat> vertex_buffer;
    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(height);
    vertex_buffer.push_back(0.0f);

    vertex_buffer.push_back(100.0f);
    vertex_buffer.push_back(height);
    vertex_buffer.push_back(0.0f);

    vertex_buffer.push_back(100.0f);
    vertex_buffer.push_back(height);
    vertex_buffer.push_back(-100.0f);

    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(height);
    vertex_buffer.push_back(0.0f);

    vertex_buffer.push_back(100.0f);
    vertex_buffer.push_back(height);
    vertex_buffer.push_back(-100.0f);

    vertex_buffer.push_back(0.0f);
    vertex_buffer.push_back(height);
    vertex_buffer.push_back(-100.0f);

    this->object = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_OCEAN, GL_FILL);
}

void Sea::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Sea::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Sea::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
	// this->position -= this->zLocal * 0.01f;
}
