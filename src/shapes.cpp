#include "shapes.h"

std::vector<GLfloat> makePrism(int nSides, double baseRadius, double height, bool ends, float x_pos, float y_pos, float z_pos)
{
    std::vector<GLfloat> vertex_buffer;
	double PI = 3.1415926535897932384626433;

	double theta = 2*PI/nSides;
	double SinTheta = sin(theta), CosTheta = cos(theta);

	float polygon_x = 0.0f, polygon_y = baseRadius;
	float xx = 0.0f, yy = baseRadius;

	for(int i=0;i<nSides;++i)
	{
		double temp_x = xx * CosTheta + yy * SinTheta;
		double temp_y = yy * CosTheta - xx * SinTheta;
	
		vertex_buffer.push_back(xx+x_pos);
		vertex_buffer.push_back(yy+y_pos);
		vertex_buffer.push_back(0+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(0+z_pos);

		vertex_buffer.push_back(xx+x_pos);
		vertex_buffer.push_back(yy+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(xx+x_pos);
		vertex_buffer.push_back(yy+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(0+z_pos);

        if(ends)
        {
            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(xx+x_pos);
            vertex_buffer.push_back(yy+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(temp_x+x_pos);
            vertex_buffer.push_back(temp_y+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);

            vertex_buffer.push_back(xx+x_pos);
            vertex_buffer.push_back(yy+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);

            vertex_buffer.push_back(temp_x+x_pos);
            vertex_buffer.push_back(temp_y+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);
        }

		xx = temp_x;
		yy = temp_y;
	}

    return vertex_buffer;
}

std::vector<GLfloat> makePyramid(int nSides, double baseRadius, double height, bool ends, float x_pos, float y_pos, float z_pos)
{
    std::vector<GLfloat> vertex_buffer;
	double PI = 3.1415926535897932384626433;

	double theta = 2*PI/nSides;
	double SinTheta = sin(theta), CosTheta = cos(theta);

	float polygon_x = 0.0f, polygon_y = baseRadius;
	float xx = 0.0f, yy = baseRadius;

	for(int i=0;i<nSides;++i)
	{
		double temp_x = xx * CosTheta + yy * SinTheta;
		double temp_y = yy * CosTheta - xx * SinTheta;
	
		vertex_buffer.push_back(xx+x_pos);
		vertex_buffer.push_back(yy+y_pos);
		vertex_buffer.push_back(0+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(0+z_pos);

		vertex_buffer.push_back(0+x_pos);
		vertex_buffer.push_back(0+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(0+x_pos);
		vertex_buffer.push_back(0+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(0+x_pos);
		vertex_buffer.push_back(0+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(0+z_pos);

        if(ends)
        {
            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(xx+x_pos);
            vertex_buffer.push_back(yy+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(temp_x+x_pos);
            vertex_buffer.push_back(temp_y+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);

            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);

            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);
        }

		xx = temp_x;
		yy = temp_y;
	}

    return vertex_buffer;
}


std::vector<GLfloat> makeFrustum(int nSides, double baseRadius, double upRadius, double height, bool ends, float x_pos, float y_pos, float z_pos)
{
    std::vector<GLfloat> vertex_buffer;
	double PI = 3.1415926535897932384626433;

	double theta = 2*PI/nSides;
	double SinTheta = sin(theta), CosTheta = cos(theta);

	float polygon_x = 0.0f, polygon_y = baseRadius;
	float xx = 0.0f, yy = baseRadius;
	float xx2 = 0.0f, yy2 = upRadius;

	for(int i=0;i<nSides;++i)
	{
		double temp_x = xx * CosTheta + yy * SinTheta;
		double temp_y = yy * CosTheta - xx * SinTheta;

        double temp_x2 = xx2 * CosTheta + yy2 * SinTheta;
		double temp_y2 = yy2 * CosTheta - xx2 * SinTheta;

		vertex_buffer.push_back(xx+x_pos);
		vertex_buffer.push_back(yy+y_pos);
		vertex_buffer.push_back(0+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(0+z_pos);

		vertex_buffer.push_back(xx2+x_pos);
		vertex_buffer.push_back(yy2+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(xx2+x_pos);
		vertex_buffer.push_back(yy2+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(temp_x2+x_pos);
		vertex_buffer.push_back(temp_y2+y_pos);
		vertex_buffer.push_back(-1*height+z_pos);

		vertex_buffer.push_back(temp_x+x_pos);
		vertex_buffer.push_back(temp_y+y_pos);
		vertex_buffer.push_back(0+z_pos);

        if(ends)
        {
            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(xx+x_pos);
            vertex_buffer.push_back(yy+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(temp_x+x_pos);
            vertex_buffer.push_back(temp_y+y_pos);
            vertex_buffer.push_back(0+z_pos);

            vertex_buffer.push_back(0+x_pos);
            vertex_buffer.push_back(0+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);

            vertex_buffer.push_back(xx2+x_pos);
            vertex_buffer.push_back(yy2+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);

            vertex_buffer.push_back(temp_x2+x_pos);
            vertex_buffer.push_back(temp_y2+y_pos);
            vertex_buffer.push_back(-1*height+z_pos);
        }

		xx = temp_x;
		yy = temp_y;
        xx2 = temp_x2;
		yy2 = temp_y2;
	}
    return vertex_buffer;
}