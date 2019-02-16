#include "main.h"

#ifndef BOMB_H
#define BOMB_H


class Bomb {
public:
    Bomb() {}
    Bomb(glm::vec3 origin, glm::vec3 velocity, glm::mat4 rotate);
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 gravity;
    glm::mat4 rotate;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
