#include "main.h"

#ifndef VOLCANO_H
#define VOLCANO_H


class Volcano {
public:
    Volcano() {}
    Volcano(glm::vec3 origin);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double speed;

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
