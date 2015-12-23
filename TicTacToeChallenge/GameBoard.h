#pragma once

#include <iostream>

class GameBoard
{
	public:
		GameBoard();
		void DisplayGameBoard();
		int GetXSelection();
		int GetYSelection();
		void UpdateGameBoard(char playerToken, int row, int col);
		bool IsPlayerMoveValid(int row, int col);
		bool DidPlayerWin(char token);
};

