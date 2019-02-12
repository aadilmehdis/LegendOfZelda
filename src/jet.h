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
    void set_position(float x, float y);
    std::vector<GLfloat> computeVertices(float radius);
    std::vector<GLfloat> icosa();
    void tick();
    double speed;

    glm::vec3 xLocal;
    glm::vec3 yLocal;
    glm::vec3 zLocal;

    void yawLeft();
    void yawRight();

    void pitchUp();
    void pitchDown();

    void rollCC();
    void rollACC();


private:
    VAO *object;
};

#endif // BALL_H
