#include <bits/stdc++.h>
#define N 8
using namespace std;

// A utility function to print solution
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

		for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	// Check lower diagonal on left side
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(int board[N][N], int col)
{
	if (col >= N)
		return true;
	for (int i = 0; i < N; i++) {
		
		if (isSafe(board, i, col)) {
			
			board[i][col] = 1;
			if (solveNQUtil(board, col + 1))
				return true;
			board[i][col] = 0; // BACKTRACK
		}
	}

	
	return false;
}

bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };
						
	 int rowOfFirstQueen = 0;
	 board[rowOfFirstQueen][0] = 1;

	if (solveNQUtil(board, 1) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board);
	return true;
}

// Driver program to test above function
int main()
{
	solveNQ();
	return 0;
}
