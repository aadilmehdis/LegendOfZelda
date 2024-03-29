#include "main.h"

#ifndef SEA_H
#define SEA_H


class Sea {
public:
    Sea() {}
    Sea(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    std::vector<GLfloat> computeVertices(float radius);
    std::vector<GLfloat> icosa();
    void tick();
    double speed;

private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H
