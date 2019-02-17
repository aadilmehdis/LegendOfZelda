#include "main.h"

#ifndef CHECKPOINT_H
#define CHECKPOINT_H


class CheckPoint {
public:
    CheckPoint() {}
    CheckPoint(glm::vec3 origin);
    glm::vec3 position;
    bool destroyed;
    bool current;
    double radius;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // BALL_H
