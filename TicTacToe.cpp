#include "TicTacToe.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv) {

	// create board
	const int BOARD_SIZE = 3;
	char board[BOARD_SIZE][BOARD_SIZE] = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
	};

	char playerTurn = 1; // 1 for X player and -1 for O player
	bool playerWin;

	// Game will go on until 9 turns have gone by
	int numOfTurns = 0;
	const int gameEnd = 9;

	// Game goes on for 9 turns
	while (numOfTurns < gameEnd) {

		PrintBoard(board);
		cout << endl;

		// inRow and inCol will hold the user input values for move row/column
		int inRow, inCol;

		// Prompt user for their move then check the validity of the move
		do {

			if (playerTurn == 1)
				cout << "X Player's turn" << endl;
			else cout << "O Player's turn" << endl;

			GetMove(&inRow, &inCol);
		} while (!MoveIsValid(board, inRow, inCol));

		// Mark X or O at the user input spot
		board[inRow][inCol] = playerTurn;

		// Check for winner
		// checks for row win
		for (int row = 0; row < BOARD_SIZE; row++) {
			for (int col = 0; col < BOARD_SIZE; col++) {

				if (board[row][col] == playerTurn)
					playerWin = true;
				else {
					playerWin = false;
					break;
				}
			}
			if (playerWin)
				break;
		}
		/*
		// Checks for column win 
		for (int col = 0; col < BOARD_SIZE; col++) {
			for (int row = 0; row < BOARD_SIZE; row++) {

				if (board[row][col] == playerTurn)
					colWinCount++;
				else {
					colWinCount = 0;
					break;
				}
			}
			if (colWinCount >= 3)
				break;
		}
		*/

		if (playerWin && numOfTurns > 4) {

			if (playerTurn == 1)
				cout << "X Player wins!" << endl;
			else
				cout << "O Player wins!" << endl;
			break;
		}
		numOfTurns++; 
		playerTurn = -playerTurn; // switch turns
	}

	PrintBoard(board); 
	cout << endl;
}

// Display the board
void PrintBoard(char board[3][3]) {

	// Top row showing numbering of columns
	cout << " - " << " 0 " << " 1 " << " 2 " << endl;

	for (int row = 0; row < 3; row++) {

		// Left column showing numbering of rows
		cout << " " << row << " ";

		for (int col = 0; col < 3; col++) {

			// Mark the empty space, X's, and O's of the board 
			// based on values 0, 1, or -1
			if (board[row][col] == 0)
				cout << " . ";
			else if (board[row][col] == 1)
				cout << " X ";
			else
				cout << " O ";
		}
		cout << endl; // Looks nicer
	}

}

// Receive user input for a move
void GetMove(int *row, int *col) {

	char commaReader; // will read the comma from cin
	cout << "Enter your move (row, column): " << endl;
	cin >> *row >> commaReader >> *col;
}

// Check if the move is legal
bool MoveIsValid(char board[3][3], int row, int col) {

	// row and col must be between 0 and 3
	// board[row][col] must be an empty space (board[row][col] = 0)
	if (row > 3 || col > 3 || row < 0 || col < 0)
		return false;
	else if (board[row][col] != 0)
		return false;
	else
		return true;
}
