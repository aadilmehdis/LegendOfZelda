#include "main.h"

#ifndef CANONBallBALL_H
#define CANONBALL_H


class CanonBall {
public:
    CanonBall() {}
    CanonBall(glm::vec3 origin, glm::vec3 target);
    glm::vec3 position;
    glm::vec3 velocity;
    glm::mat4 rotate;
    double radius;
    void draw(glm::mat4 VP);
    void tick();

private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // BALL_H
