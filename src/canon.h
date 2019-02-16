#include "main.h"

#ifndef CANON_H
#define CANON_H


class Canon {
public:
    Canon() {}
    Canon(glm::vec3 origin);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
