#include "GameBoard.h";

#include <iostream>

using namespace std;

GameBoard board;

void StartGame();
bool PlayerTurn(int row, int col);
void UpdateGameBoard(char token, int row, int col);
int main()
{
	cout << "Lets play a game of tic tac toe!!!!!!" << endl << endl;

	StartGame();

	system("pause");
	return 0;
}

void StartGame()
{
	bool IsGameOver = false;

	while (IsGameOver == false)
	{
		bool isValidMove = false;
		cout << "Player 1 turn" << endl;
		int row = board.GetXSelection();
		int col = board.GetYSelection();

		while (isValidMove == false)
		{
			isValidMove = PlayerTurn(row, col);
		}

		UpdateGameBoard('X', row, col);

		if (board.DidPlayerWin('X'))
		{
			cout << "Player One Wins" << endl;
			IsGameOver = true;
			break;
		}

		isValidMove = false;

		cout << "Player 2 turn" << endl;
		row = board.GetXSelection();
		col = board.GetYSelection();

		while (isValidMove == false)
		{
			isValidMove = PlayerTurn(row, col);
		}

		UpdateGameBoard('O', row, col);

		if (board.DidPlayerWin('O'))
		{
			cout << "Player Two Wins" << endl;
			IsGameOver = true;
			break;
		}
	}
	
}

bool PlayerTurn(int row, int col)
{
	bool valid = false;

	if (board.IsPlayerMoveValid(row, col))
	{
		valid = true;
	}
	else
	{
		cout << "The move was not valid!!!!" << endl;
		row = board.GetXSelection();
		col = board.GetYSelection();
	}

	return valid;
}

void UpdateGameBoard(char token, int row, int col)
{
	board.UpdateGameBoard(token, row, col);
	board.DisplayGameBoard();
}