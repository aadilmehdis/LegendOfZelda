#include "main.h"

#ifndef RING_H
#define RING_H


class Ring {
public:
    Ring() {}
    Ring(glm::vec3 origin);
    glm::vec3 position;
    double rotation;
    double radius;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
