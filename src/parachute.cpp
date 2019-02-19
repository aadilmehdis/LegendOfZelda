#include "parachute.h"
#include "main.h"
#include "shapes.h"

Parachute::Parachute(glm::vec3 origin) {
    this->position = origin;
    this->rotation = 0;
    this->radius = 6;
    this->acceleration = 0.3;

	float z_pullBack = 5;

    std::vector<GLfloat> vertex_buffer = makeHalfTorus(20, 1,1.25,1,0,0,0);
    std::vector<GLfloat> vertex_buffer1 = makePrism(20,0.15,0.15,true,-1,0,-0.5);
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer1.begin(), vertex_buffer1.end());

    for(int i=0;i<vertex_buffer.size();++i)
    {
        vertex_buffer[i] *= 4;
    }

    std::vector<GLfloat> vertex_buffer4;

    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(4);
    vertex_buffer4.push_back(0);

    vertex_buffer4.push_back(-4);
    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(-2);

    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(-4);
    vertex_buffer4.push_back(0);

    vertex_buffer4.push_back(-4);
    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(-2);


    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(4);
    vertex_buffer4.push_back(-4);

    vertex_buffer4.push_back(-4);
    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(-2);

    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(-4);
    vertex_buffer4.push_back(-4);

    vertex_buffer4.push_back(-4);
    vertex_buffer4.push_back(0);
    vertex_buffer4.push_back(-2);

    std::vector<GLfloat> vertex_buffer3;
    vertex_buffer3.push_back(0.0f);
    vertex_buffer3.push_back(0.0f);
    vertex_buffer3.push_back(0.0f);


    vertex_buffer3.push_back(this->radius);
    vertex_buffer3.push_back(0.0f);
    vertex_buffer3.push_back(0.0f);

    this->object1 = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_LAVA, GL_FILL);
    this->object2 = create3DObject(GL_LINES, vertex_buffer4.size()/3, vertex_buffer4.data(), COLOR_LAVA, GL_FILL);
    this->object3 = create3DObject(GL_LINES, vertex_buffer.size()/3, vertex_buffer.data(), COLOR_SUNFLOWER, GL_LINE);
    this->object4 = create3DObject(GL_LINES, vertex_buffer4.size()/3, vertex_buffer4.data(), COLOR_SUNFLOWER, GL_LINE);
}

void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef

    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 rotate    = glm::rotate((float) (90 * M_PI / 180.0f), glm::vec3(0,0,1));
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1,0));
    Matrices.model *= (translate * rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}


void Parachute::tick(glm::vec3 plane_pos) {
    this->velocity = glm::normalize(plane_pos - this->position) * this->acceleration;
    this->position += this->velocity;
}