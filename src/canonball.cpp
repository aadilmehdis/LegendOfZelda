#include "canonball.h"
#include "main.h"
#include "shapes.h"

CanonBall::CanonBall(glm::vec3 origin, glm::vec3 target) {
    this->position = origin;

    glm::vec3 dir = -1.0f * (target - this->position);
    dir = glm::normalize(dir);
    this->rotate[2] = glm::vec4(dir,0);
    glm::vec3 r1 = glm::normalize(glm::cross(dir,glm::vec3(1,0,0)));
    glm::vec3 r2 = glm::normalize(glm::cross(r1,dir));
    this->rotate[1] = glm::vec4(r2,0);
    this->rotate[0] = glm::vec4(r1,0);
    this->rotate[3] = glm::vec4(0,0,0,1);

    this->velocity = dir*2.0f;

	float z_pullBack = 0;
	float y_pullBack = 0;

    std::vector<GLfloat> vertex_buffer = makeFrustum(20, 2, 1.5, 1, true, 0, 0 + y_pullBack, 0 + z_pullBack);
    std::vector<GLfloat> vertex_buffer1 = makeFrustum(20, 1.5, 1.0, 1, true, 0, 0 + y_pullBack, -1 + z_pullBack);
    std::vector<GLfloat> vertex_buffer2 = makeFrustum(20, 1.5, 2, 1, true, 0, 0 + y_pullBack, 1 + z_pullBack);
    std::vector<GLfloat> vertex_buffer3 = makeFrustum(20, 1.0, 1.5, 1, true, 0, 0 + y_pullBack, 2 + z_pullBack);

	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer1.begin(), vertex_buffer1.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer2.begin(), vertex_buffer2.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_LAVA, GL_LINE);
}

void CanonBall::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    // glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1,0,0));
    Matrices.model *= (translate * this->rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}


void CanonBall::tick() {
    // glm::vec3 dir = -1.0f * (plane_pos - this->position);
    // dir = glm::normalize(dir);
    // this->rotate[2] = glm::vec4(dir,0);
    // glm::vec3 r1 = glm::normalize(glm::cross(dir,glm::vec3(1,0,0)));
    // glm::vec3 r2 = glm::normalize(glm::cross(r1,dir));
    // this->rotate[1] = glm::vec4(r2,0);
    // this->rotate[0] = glm::vec4(r1,0);
    // this->rotate[3] = glm::vec4(0,0,0,1);
    this->position -= this->velocity;
}
