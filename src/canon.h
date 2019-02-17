#include "main.h"

#ifndef CANON_H
#define CANON_H


class Canon {
public:
    Canon() {}
    Canon(glm::vec3 origin);
    glm::vec3 position;
    glm::mat4 rotate;
    void draw(glm::mat4 VP);
    void tick(glm::vec3 plane_pos);

private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H
