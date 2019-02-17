#include "main.h"

#ifndef JET_H
#define JET_H


class Jet {
public:
    Jet() {}
    Jet(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void tick();
    double speed;

    glm::vec3 xLocal;
    glm::vec3 yLocal;
    glm::vec3 zLocal;
    glm::vec3 velocity;
    float acceleration;

    void yawLeft();
    void yawRight();

    void pitchUp();
    void pitchDown();

    void rollCC();
    void rollACC();


private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *frame1;
    // VAO *frame2;
    // VAO *frame3;
    VAO *crosshair;
};

#endif // BALL_H
