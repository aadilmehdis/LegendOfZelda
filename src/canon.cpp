#include "canon.h"
#include "main.h"
#include "shapes.h"

Canon::Canon(glm::vec3 origin) {
    this->position = origin;

	float z_pullBack = 3.7;
	float y_pullBack = 0;

    std::vector<GLfloat> vertex_buffer = makeFrustum(20, 4, 1, 10, true, 0, 0 + y_pullBack, 0 + z_pullBack);
    std::vector<GLfloat> vertex_buffer1 = makeFrustum(20, 2, 4, 4, true, 0, 0 + y_pullBack, 4 + z_pullBack);

	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer1.begin(), vertex_buffer1.end());
	// vertex_buffer.insert(vertex_buffer.end(), vertex_buffer2.begin(), vertex_buffer2.end());
	// vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());


    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_DARK_BROWN, GL_LINE);
}

void Canon::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 rotate    = glm::rotate((float) (90 * M_PI / 180.0f), glm::vec3(1,0,0));
    Matrices.model *= (translate * rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}


void Canon::tick() {
}
