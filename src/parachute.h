#include "main.h"

#ifndef PARACHUTE_H
#define PARACHUTE_H


class Parachute {
public:
    Parachute() {}
    Parachute(glm::vec3 origin);
    glm::vec3 position;
    glm::vec3 velocity;
    double rotation;
    double radius;
    float acceleration;
    bool current;
    void draw(glm::mat4 VP);
    void tick(glm::vec3 plane_pos);

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
