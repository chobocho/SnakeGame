#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#pragma once
class CFood
{
public:
	CFood(int n = 3);
	void init(int n = 3);
	void remove(pair<int, int> bug) {
		auto it = mBug.begin();
		for (; it != mBug.end(); ++it) {
			if (*it == bug) {
				break;
			}
		}
		if (it != mBug.end()) {
			mBug.erase(it);
		}
	}
	vector< pair<int, int> > getBugList() { return mBug; }
	~CFood();
private:
	vector< pair<int, int> > mBug;
};

