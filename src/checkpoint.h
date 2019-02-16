#include "main.h"

#ifndef CHECKPOINT_H
#define CHECKPOINT_H


class CheckPoint {
public:
    CheckPoint() {}
    CheckPoint(glm::vec3 origin);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
