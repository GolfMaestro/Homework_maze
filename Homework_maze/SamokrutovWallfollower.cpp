#include <iostream>
#include <vector>
#include "SamokrutovWallFollower.h"
#include "maze.h"

#define ROW rows
#define COL columns
using namespace std;

vector<vector<int>> maze_copy_wallfollower;


void CopyMaze_wallfollower(const vector<vector<int>>& maze) {
	maze_copy_wallfollower = maze;
}

bool isSafe(int row, int col, const vector<vector<int>>& maze_copy_wallfollower, vector<vector<bool>>& visited) {
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (maze_copy_wallfollower[row][col] != 1) && !visited[row][col];
}

bool findExit(vector<vector<int>>& maze_copy_wallfollower, int row, int col, int exitRow, int exitCol,
	std::vector<std::vector<bool>>& visited) {
	if (row == exitRow && col == exitCol) {
		return true;
	}

	visited[row][col] = true;

	int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	for (int i = 0; i < 4; ++i) {
		int nextDirX = row + directions[i][0];
		int nextDirY = col + directions[i][1];

		if (isSafe(nextDirX, nextDirY, maze_copy_wallfollower, visited)) {
			if (maze_copy_wallfollower[nextDirX][nextDirY] == 0) {
				maze_copy_wallfollower[nextDirX][nextDirY] = 2; // Помечаем путь значением 2 только если текущая ячейка содержит 0
			}

			if (findExit(maze_copy_wallfollower, nextDirX, nextDirY, exitRow, exitCol, visited)) {
				return true;
			}
		}
	}

	return false;
}



bool maze_main_wallfollower(const vector<vector<int>>& maze) {
	vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
	CopyMaze_wallfollower(maze);
	int startX = 0, startY = 0; // Начальная позиция
	int exitX = 0, exitY = 0;   // Позиция выхода

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (maze[i][j] == 0) {
				startX = 11;
				startY = 0;
			}
			else if (maze[i][j] == 4) {
				exitX = i;
				exitY = j;
			}
		}
	}

	if (findExit(maze_copy_wallfollower, startX, startY, exitX, exitY, visited)) {
		std::cout << "Succes!" << std::endl;
	}
	else {
		std::cout << "Fail!" << std::endl;
	}


	// Вывод лабиринта с отмеченным путем
	/*for (int i = 0; i < ROW; ++i) {
	  for (int j = 0; j < COL; ++j) {
		std::cout << maze_copy_wallfollower[i][j] << " ";
	  }
	  std::cout << std::endl;
	}*/

	return 0;
}



	// Вывод лабиринта с отмеченным путем
	/*for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			std::cout << maze_copy_wallfollower[i][j] << " ";
		}
		std::cout << std::endl;
	}*/