#include "GameBoard.h"

using namespace std;

const int maxRows = 3;
const int maxCol = 3;
static char boardArray[maxRows][maxCol];

GameBoard::GameBoard()
{
	for (int y = 0; y < maxCol; y++)
	{
		for (int x = 0; x < maxRows; x++)
		{
			boardArray[y][x] = '*';
		}
	}
}

void GameBoard::DisplayGameBoard()
{
	for (int y = 0; y < maxCol; y++)
	{
		for (int x = 0; x < maxRows; x++)
		{
			cout << boardArray[y][x];
		}
		cout << endl;
	}
}

int GameBoard::GetXSelection()
{
	int row;
	bool isInputBad = true;

	while (isInputBad == true)
	{
		cout << "Enter the row number you wish to play starting with 0 from the top to 2 at the bottom" << endl;
		cin >> row;

		if (!cin)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input is invalid" << endl;
		}
		else
		{
			if (row >= 0 && row < 4)
			{
				isInputBad = false;
			}
			else
			{
				cout << "Input is invalid" << endl;
			}
		}
	}

	return row;
}

int GameBoard::GetYSelection()
{
	int col;
	bool isInputBad = true;

	while (isInputBad == true)
	{
		cout << "Enter the column number you wish to play starting with 0 from the left to 2 at the right" << endl;
		cin >> col;

		if (!cin)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input is invalid" << endl;
		}
		else
		{
			if (col >= 0 && col < 4)
			{
				isInputBad = false;
			}
			else
			{
				cout << "Input is invalid" << endl;
			}
		}
	}

	return col;
}

void GameBoard::UpdateGameBoard(char playerToken, int row, int col)
{
	boardArray[row][col] = playerToken;
}

bool GameBoard::IsPlayerMoveValid(int row, int col)
{
	if (boardArray[row][col] != 'X' && boardArray[row][col] != 'O')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameBoard::DidPlayerWin(char token)
{
	if (boardArray[0][0] == token && boardArray[0][1] == token && boardArray[0][2] == token)
	{
		return true;
	}
	else if (boardArray[1][0] == token && boardArray[1][1] == token && boardArray[1][2] == token)
	{
		return true;
	}
	else if (boardArray[2][0] == token && boardArray[2][1] == token && boardArray[2][2] == token)
	{
		return true;
	}
	else if (boardArray[0][0] == token && boardArray[1][0] == token && boardArray[2][0] == token)
	{
		return true;
	}
	else if (boardArray[0][1] == token && boardArray[1][1] == token && boardArray[2][1] == token)
	{
		return true;
	}
	else if (boardArray[0][2] == token && boardArray[1][2] == token && boardArray[2][2] == token)
	{
		return true;
	}
	else if (boardArray[0][0] == token && boardArray[1][1] == token && boardArray[2][2] == token)
	{
		return true;
	}
	else if (boardArray[0][2] == token && boardArray[1][1] == token && boardArray[2][0] == token)
	{
		return true;
	}
	else
	{
		return false;
	}
}


