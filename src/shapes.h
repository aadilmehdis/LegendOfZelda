#include "main.h"

#ifndef SHAPES_H
#define SHAPES_H

std::vector<GLfloat> makePrism(int nSides, double baseRadius, double height, bool ends, float x_pos, float y_pos, float z_pos);
std::vector<GLfloat> makePyramid(int nSides, double baseRadius, double height, bool ends, float x_pos, float y_pos, float z_pos);
std::vector<GLfloat> makeFrustum(int nSides, double baseRadius, double upRadius, double height, bool ends, float x_pos, float y_pos, float z_pos);

#endif