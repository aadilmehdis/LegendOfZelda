#include "ball.h"
#include "main.h"
#include "shapes.h"

Ball::Ball(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;

	std::vector<GLfloat> vertex_buffer = makePrism(10,1, 10, false,0,0, 0);
	std::vector<GLfloat> vertex_buffer2 = makeFrustum(10, 1, 0.6, 1, false,0,0, -10);
	std::vector<GLfloat> vertex_buffer3 = makeFrustum(10,0.8,1,0.8,true,0,0,0.8);
	std::vector<GLfloat> vertex_buffer4 = makePrism(10,0.6, 2, true,2.5,0, -5.5);
	std::vector<GLfloat> vertex_buffer5 = makePrism(10,0.6, 2, true,-2.5,0, -5.5);
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer2.begin(), vertex_buffer2.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer4.begin(), vertex_buffer4.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer5.begin(), vertex_buffer5.end());
	
	//tail
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-3);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(3);
	vertex_buffer.push_back(0.5);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(3);
	vertex_buffer.push_back(0.5);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(3);
	vertex_buffer.push_back(2);
	//tail close

	//fin
	vertex_buffer.push_back(-4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-3);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(4.3);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(1);


	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(-4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);

	vertex_buffer.push_back(-4.3);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(1);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-8);

	vertex_buffer.push_back(7);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-6);

	vertex_buffer.push_back(-7);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-6);
	//fin close



    this->object = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), color, GL_LINE);
}

void Ball::draw(glm::mat4 VP) {
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

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}