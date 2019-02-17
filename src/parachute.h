#include "main.h"

#ifndef PARACHUTE_H
#define PARACHUTE_H


class Parachute {
public:
    Parachute() {}
    Parachute(glm::vec3 origin);
    glm::vec3 position;
    double rotation;
    bool current;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
};

#endif // BALL_H
