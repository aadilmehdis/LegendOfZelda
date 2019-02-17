#include "main.h"

#ifndef MISSILE_H
#define MISSILE_H


class Missile {
public:
    Missile() {}
    Missile(glm::vec3 origin, glm::vec3 velocity, glm::mat4 rotate);
    glm::vec3 position;
    glm::vec3 velocity;
    glm::mat4 rotate;
    float rotation;
    double radius;
    void draw(glm::mat4 VP);
    void tick();
    double speed;

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
