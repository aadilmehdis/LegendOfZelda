#include "main.h"

#ifndef HEALTH_H
#define HEALTH_H


class Health {
public:
    Health() {}
    Health(glm::vec3 origin);
    glm::vec3 position;
    double rotation;
    bool current;
    double radius;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H
