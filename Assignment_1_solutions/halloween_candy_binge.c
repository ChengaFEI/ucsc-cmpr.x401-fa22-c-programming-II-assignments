
// Help Pacman collect the maximum number of
// points while eating candy! Each room is shown
// with a square in the grid.  A room may contain a packet of red
// or blue sour candy, and Pacman get 2 points on eating a packet
// of red sours and 3 points on eating a packet of blue sours.  Moves
// are in the N, S, E, and W directions along adjacent rooms, called a path
// Some rooms contain ghosts and Pacman freezes upon.
// reaching a room with a ghost. Note that Pacman cannot visit
// any room more than once on a given path. Given a
// starting location, determine the maximum number of
// points on any path that Pacman can collect before freezing.
// PACMAN with candy and ghosts

// This solution records the current value  of grid in local variable (prevValue), and marks
// this grid and row as visited (grid[row][col] = 'V'). It restores this value before returning.
// Copyright SPEL Technologies, Inc.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


#define MAX_SIZE 100

int path[MAX_SIZE];
char grid[MAX_SIZE][MAX_SIZE];
int maxPoints = INT_MIN;
int numRows, numCols;

bool isVisited(int row, int col, int size) {
	int roomNum = row * numCols + col;

	bool visited = false;
	for (int i = 0; i < size && visited == false; i++) {
		if (roomNum == path[i]) {
			visited = true;
		}
	}
	return visited;
}

void displayGrid() {
	for (int i  = 0; i < numRows; i++) {
		for (int j  = 0; j < numCols; j++) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
}


void move(int row, int col, int points) {


	if (grid[row][col] == 'V') {
		return;
	}

	if (grid[row][col] == 'T')       // points for eating sour
		points = points + 3;
	else if (grid[row][col] == 'S')  // points for eating sour
		points = points + 2;
	else if (grid[row][col] == 'G')  { // encountered ghost
		if (points > maxPoints) {
			maxPoints = points;
		}
		return;
	}

	char prevValue = grid[row][col];
	grid[row][col] = 'V'; // mark this grid as having been visited.

	if (row < numRows - 1) move (row+1, col, points);
	if (row > 0) move (row - 1, col, points);
	if (col < numCols - 1) move (row, col+1, points);
	if (col > 0) move (row, col - 1, points);

	// replace original value in the grid position before returning
	grid[row][col] = prevValue;
}

int main() {
	int numTestCases, startRow, startCol;
	printf("%s\n", "In Pacman1.c" );
	freopen("halloween_candy_binge_input.txt", "r", stdin);   
	scanf("%d", &numTestCases);
        
	for (int testi = 0; testi < numTestCases; testi++) {
		maxPoints = INT_MIN;
		scanf("%d", &numRows);
		scanf("%d", &numCols);
		scanf("%d", &startRow);
		scanf("%d", &startCol);

		for (int i  = 0; i < numRows; i++) {
			for (int j  = 0; j < numCols; j++) {
				scanf(" %c", &grid[i][j]);
			}
		}
             
		printf("Test case: %d\n" ,testi);
		move(startRow, startCol, 0);
		printf("Max points collected: %d\n" , maxPoints);

	}
	return 0;
}


