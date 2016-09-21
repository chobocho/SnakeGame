#include "Food.h"
#include <utility>
using namespace std;


CFood::CFood(int n)
{
	srand(time(NULL));
	init(n);

}


CFood::~CFood()
{
}

void CFood::init(int n) {
	for (int i = 0; i < n; ++i) {
		pair<int, int> newBug;
		newBug.first = rand() % 79 + 1;
		newBug.second = rand() % 23 + 1;
		mBug.push_back(newBug);
	}
}