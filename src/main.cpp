/*
 Title : SnakeGame 
 Date : 2016. 9. 14
 Update : 
 */

#include<iostream>
#include<windows.h>
#include"Snake.h"
#include"SnakeView.h"
using namespace std;

void PlaySnakeGame();

int main(int argc, char **argv) {
	PlaySnakeGame();
	return 0;
}

void PlaySnakeGame() {
	// Init 
	CSnake player1, player2, complayer;
	SnakeView snakeGame;

	snakeGame.init();
	snakeGame.setPlayer1(&player1);
	snakeGame.setPlayer2(&player2);
	snakeGame.setComPlayer(&complayer);

	snakeGame.start();
}