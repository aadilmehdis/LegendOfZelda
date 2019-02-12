#include "jet.h"
#include "main.h"
#include "shapes.h"

Jet::Jet(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
	this->xLocal = glm::vec3(1, 0, 0);
	this->yLocal = glm::vec3(0, 1, 0);
	this->zLocal = glm::vec3(0, 0, 1);

    this->rotation = 0;
    speed = 1;

	float z_pullBack = 5;

	std::vector<GLfloat> vertex_buffer = makePrism(10,1, 10, false,0,0, 0 + z_pullBack);
	std::vector<GLfloat> vertex_buffer2 = makeFrustum(10, 1, 0.6, 1, false,0,0, -10 + z_pullBack);
	std::vector<GLfloat> vertex_buffer3 = makeFrustum(10,0.8,1,0.8,true,0,0,0.8 + z_pullBack);
	std::vector<GLfloat> vertex_buffer4 = makePrism(10,0.6, 2, true,2.5,0, -5.5 + z_pullBack);
	std::vector<GLfloat> vertex_buffer5 = makePrism(10,0.6, 2, true,-2.5,0, -5.5 + z_pullBack);
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer2.begin(), vertex_buffer2.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer3.begin(), vertex_buffer3.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer4.begin(), vertex_buffer4.end());
	vertex_buffer.insert(vertex_buffer.end(), vertex_buffer5.begin(), vertex_buffer5.end());
	
	//tail
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-3 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(3);
	vertex_buffer.push_back(0.5 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(3);
	vertex_buffer.push_back(0.5 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(3);
	vertex_buffer.push_back(2 + z_pullBack);
	//tail close

	//fin
	vertex_buffer.push_back(-4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-3 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(4.3);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(1 + z_pullBack);


	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(-4);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0 + z_pullBack);

	vertex_buffer.push_back(-4.3);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(1 + z_pullBack);

	vertex_buffer.push_back(0);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-8 + z_pullBack);

	vertex_buffer.push_back(7);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-6 + z_pullBack);

	vertex_buffer.push_back(-7);
	vertex_buffer.push_back(0);
	vertex_buffer.push_back(-6 + z_pullBack);
	//fin close



    this->object = create3DObject(GL_TRIANGLES, vertex_buffer.size()/3, vertex_buffer.data(), color, GL_LINE);
}

void Jet::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));

	glm::mat4 rotate;
	rotate[0] = glm::vec4(xLocal,0);
	rotate[1] = glm::vec4(yLocal,0);
	rotate[2] = glm::vec4(zLocal,0);
	rotate[3] = glm::vec4(0,0,0,1);
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);

    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Jet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Jet::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
	this->position -= this->zLocal * 0.1f;
}

void Jet::yawLeft() {
	glm::mat4 rotate    = glm::rotate((float) (-1.0 * M_PI / 180.0f), yLocal);
	this->xLocal 				= glm::vec3(rotate * glm::vec4(xLocal,0.0));
	this->zLocal 				= glm::vec3(rotate * glm::vec4(zLocal,0.0));
	// this->xLocal 				= glm::vec3(rotate[0]);
	// this->zLocal 				= glm::vec3(rotate[2]);
}

void Jet::yawRight() {
	glm::mat4 rotate    = glm::rotate((float) (1 * M_PI / 180.0f), yLocal);
	this->xLocal 				= glm::vec3(rotate * glm::vec4(xLocal,0.0));
	this->zLocal 				= glm::vec3(rotate * glm::vec4(zLocal,0.0));
}

void Jet::pitchUp() {
	glm::mat4 rotate    = glm::rotate((float) (1 * M_PI / 180.0f), xLocal);
	this->yLocal 				= glm::vec3(rotate * glm::vec4(yLocal,0.0));
	this->zLocal 				= glm::vec3(rotate * glm::vec4(zLocal,0.0));
}

void Jet::pitchDown() {
	glm::mat4 rotate    = glm::rotate((float) (-1 * M_PI / 180.0f), xLocal);
	this->yLocal 				= glm::vec3(rotate * glm::vec4(yLocal,0.0));
	this->zLocal 				= glm::vec3(rotate * glm::vec4(zLocal,0.0));
}

void Jet::rollCC() {
	glm::mat4 rotate    = glm::rotate((float) (-1 * M_PI / 180.0f), zLocal);
	this->xLocal 				= glm::vec3(rotate * glm::vec4(xLocal,0.0));
	this->yLocal 				= glm::vec3(rotate * glm::vec4(yLocal,0.0));
}

void Jet::rollACC() {
	glm::mat4 rotate    = glm::rotate((float) (1 * M_PI / 180.0f), zLocal);
	this->xLocal 				= glm::vec3(rotate * glm::vec4(xLocal,0.0));
	this->yLocal 				= glm::vec3(rotate * glm::vec4(yLocal,0.0));
}