#include "SnakeView.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
using namespace std;


SnakeView::SnakeView()
{
}


SnakeView::~SnakeView()
{
}

void SnakeView::gotoxy(int x, int y, char* s) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << s << endl;
}

void SnakeView::gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SnakeView::start() {
	init();
	showMainScreen();
}

void SnakeView::init() {

	mGameState = GAME_INIT;
	mPlayerNum = 0;
	mStage = 1;

}

void SnakeView::showMainScreen() {
	cout << "How many player?" << endl;
	cout << "1. 1player " << endl;
	cout << "2. 2player " << endl;
	cout << "3. 1player + Com" << endl;
	cout << "4. 21player + Com " << endl;
	cout << "5. Quit \n ->" << endl;

	int key;
	bool isQuit = false;

	do {

		key = getchar();
		cout << key << endl;

		switch (key) {
		case '1':
			start_1P_game();
			break;
		case '5':
			isQuit = true;
			break;
		default:
			break;
		}
	} while (key < '1' || key > '5' );

}

void SnakeView::start_1P_game() {
	mPlayer1->setLife(1);
	mPlayer1->addBody(Point(rand() % 79 + 1, rand() % 23 + 1));
	mGameState = GAME_PLAY_1P;

	
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

	clearScreen();

	Point nextPoint = mPlayer1->getHead();
	int dir = -1;
	int count = 0;
	int addSize = 0;
	bool isStageFinish = false;
	onDraw();

	while (mPlayer1 -> getLife() > 0) {

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			dir = -1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			dir =  1;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			dir =  -2;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			dir = 2;
		}
		if (GetAsyncKeyState('P') & 0x8000) {
			cout << "P pressed" << endl;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "ESC pressed" << endl;
			break;
		}

		count++;

		if (count % mPlayer1->getSpeed() == 0) {

			if (mPlayer1->getDirection() == dir * (-1)) {
				dir = mPlayer1->getDirection();
			}
			switch (dir) {
			case -1:
				nextPoint.first--;
				break;
			case 1:
				nextPoint.first++;
				break;
			case -2:
				nextPoint.second--;
				break;
			case 2:
				nextPoint.second++;
				break;
			default:
				cout << "Error " << endl;
				break;
			}
			mPlayer1->setDirection(dir);
			mPlayer1->addBody(nextPoint);

			for (Point bug : mFood.getBugList()) {
				if (bug == nextPoint) {
					addSize += 2;
					mFood.remove(bug);
					if (mPlayer1->getSpeed() > 5) {
						mPlayer1->speedup();
					}

					if (mFood.getBugList().empty()) {
						isStageFinish = true;
					}
					break;
				}
			}
	
			if (addSize >= 1) {
				--addSize;
			}
			else {
				gotoxy(mPlayer1->getTail().first, mPlayer1->getTail().second, " ");
				mPlayer1->removeTail();
			}
			onDraw();

			if (isStageFinish) {
				clearScreen();
				mStage++;
				addSize = mStage;
				mPlayer1->init();
				mPlayer1->addBody(Point(rand() % 79 + 1, rand() % 23 + 1));
				mFood.init(mStage * 2 + 3);
				isStageFinish = false;
			}
		}
		Sleep(8);
		
	}
}

void SnakeView::onDraw() {
	switch (mGameState) {
	case GAME_PLAY_1P:
		for (Point p : mPlayer1->getSnakeBody()) {
			gotoxy(p.first, p.second, "O");
		}

		for (Point p : mFood.getBugList()) {
			gotoxy(p.first, p.second, "X");
		}

		gotoxy(mPlayer1->getHead().first, mPlayer1->getHead().second, "H");

		break;
	default:
		break;
	}
}

void SnakeView::clearScreen() {
	for (int i = 0; i < 80; i++) {
		for (int j = 0; j < 24; j++) {
			gotoxy(i, j, " ");
		}
	}
}

void SnakeView::start_2P_game() {
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			cout << "LEFT pressed" << endl;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			cout << "RIGHT pressed" << endl;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			cout << "UP pressed" << endl;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			cout << "DOWN pressed" << endl;
		}


		if (GetAsyncKeyState('W') & 0x8000) {
			cout << "W pressed" << endl;
		}
		if (GetAsyncKeyState('A') & 0x8000) {
			cout << "A pressed" << endl;
		}
		if (GetAsyncKeyState('S') & 0x8000) {
			cout << "S pressed" << endl;
		}
		if (GetAsyncKeyState('D') & 0x8000) {
			cout << "D pressed" << endl;
		}

		if (GetAsyncKeyState('P') & 0x8000) {
			cout << "P pressed" << endl;
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			cout << "ESC pressed" << endl;
			break;
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			cout << "SPACE pressed" << endl;
		}
		else {
			//cout << "NO pressed" << endl;
		}
	}
}

void SnakeView::start_1P_com_game() { }
void SnakeView::start_2P_com_game() { }