#include "main.h"

#ifndef ARROW_H
#define ARROW_H


class Arrow {
public:
    Arrow() {}
    Arrow(glm::vec3 origin);
    glm::vec3 position;
    double rotation;
    bool current;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H
