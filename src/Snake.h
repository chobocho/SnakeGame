#pragma once
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> Point;

class CSnake
{
public:
	CSnake(int life = 3);
	~CSnake();
	void  init(int life = 3);
	Point getHead();
	Point getTail() { return mSnakeBody.back(); }
	int   getLife() { return mLife;  }
	void  setLife(int i) { mLife = i; }
	int   getSpeed() { return mSpeed;  }
	void  setSpeed(int s) { mSpeed = s; }
	void  speedup() {  --mSpeed; }
	int   getDirection() { return mDirection;  }
	void  setDirection(int d) { mDirection = d; }
	int   addBody(Point p);
	void  removeTail() { mSnakeBody.pop_back(); }
	vector<Point> getSnakeBody();
  
	enum {
		SNAKE_UP    =  -2, 
	    SNAKE_LEFT  =  -1,
		SNAKE_DOWN  =  2,
	    SNAKE_RIGHT =  1
	};

private:
	vector<Point> mSnakeBody;
	int mDirection;
	int mLife;
	int mScore;
	int mSpeed;
};

