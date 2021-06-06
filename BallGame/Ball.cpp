#include "Headers.h"
Ball::Ball()
{
	x = rand() %700;
	y = 745-rand() %700;
	radius = 20;
	theta = 60;
	speed = 0.1;
}

int Ball::getRadius()
{
	return radius;
}
void Ball::setRadius(int radius)
{
	this->radius = radius;
}
GLfloat Ball::getAngle()
{
	return theta;
}
void Ball::setAngle(GLfloat theta)
{
	this->theta = theta;
}

void Ball::reverseX()
{
	theta = PI - theta;
}
void Ball::reverseY()
{
	theta = 2 * PI - theta;
}
void Ball::update()
{
	x += speed * cos(theta);
	y += speed * sin(theta);

	if (y > 745 - radius)
	{
		reverseY();
		y = 745 - radius;
	}
	else if (x < radius)
	{
		reverseX();
		x = radius;
	}
	else if (x > 700 - radius)
	{
		reverseX();
		x = 700 - radius;
	}
	if (y < 45 + radius)
	{
		reverseY();
		y = 45 + radius;
	}
}


void Ball::draw()
{
	Draw::setColor(1,1,1);
	Draw::filledCircle(x, y, radius);
}

GLfloat Ball::getSpeed()
{
	return speed;
}
void Ball::setSpeed(GLfloat speed)
{
	this->speed = speed;
}