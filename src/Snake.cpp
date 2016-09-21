#include "Snake.h"



CSnake::CSnake(int life)
{
	init(life);
}

CSnake::~CSnake()
{

}

void CSnake::init(int life) {
	mDirection = SNAKE_DOWN;
	mLife = life;
	mSpeed = 30;
	mSnakeBody.clear();
}

Point CSnake::getHead() {
	return mSnakeBody.front();
}

int CSnake::addBody(Point p) {
	mSnakeBody.insert(mSnakeBody.begin(), p);
	return 0;
}

vector<Point> CSnake::getSnakeBody() {
	return mSnakeBody;
}