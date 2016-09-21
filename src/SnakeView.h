#include"Snake.h"
#include"Food.h"
#pragma once
class SnakeView
{
public:
	SnakeView();
	~SnakeView();

	enum {
		GAME_INIT,
		GAME_MAIN_SCREEN,
		GAME_PLAY_1P,
		GAME_PLAY_2P,
		GAME_PLAY_1P_COM,
		GAME_PLAY_2P_COM,
		GAME_PAUSE,
		GAME_END
	};

	void start();
	void init();
	void playGame();
	void showMainScreen();
	void clearScreen();
	void onDraw();
	void setPlayer1  (CSnake *s)  { mPlayer1  = s; }
	void setPlayer2  (CSnake *s)  { mPlayer2  = s; }
	void setComPlayer(CSnake *s) { mComPlayer = s; }

	void start_1P_game();
	void start_2P_game();
	void start_1P_com_game();
	void start_2P_com_game();

private:
	void gotoxy(int x, int y, char* s);
	void gotoxy(int x, int y);

	CSnake* mPlayer1;
	CSnake* mPlayer2;
	CSnake* mComPlayer;
	CFood   mFood;

	int mGameState;
	int mPlayerNum;
	int mStage;
};

