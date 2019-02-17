#include "main.h"

#ifndef FUELTANK_H
#define FUELTANK_H


class FuelTank {
public:
    FuelTank() {}
    FuelTank(glm::vec3 origin);
    glm::vec3 position;
    double rotation;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
};

#endif // BALL_H
