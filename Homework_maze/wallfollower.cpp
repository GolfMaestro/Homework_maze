#include <iostream>
#include <vector>

#define ROW 12
#define COL 12

bool isSafe(int row, int col, const std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& visited) {
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (matrix[row][col] != 1) && !visited[row][col];
}

bool findExit(std::vector<std::vector<int>>& matrix, int row, int col, int exitRow, int exitCol,
	std::vector<std::vector<bool>>& visited) {
	if (row == exitRow && col == exitCol) {
		return true;
	}

	visited[row][col] = true;

	int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	for (int i = 0; i < 4; ++i) {
		int nextDirX = row + directions[i][0];
		int nextDirY = col + directions[i][1];

		if (isSafe(nextDirX, nextDirY, matrix, visited)) {
			matrix[nextDirX][nextDirY] = 2; // Помечаем путь значением 2

			if (findExit(matrix, nextDirX, nextDirY, exitRow, exitCol, visited)) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	std::vector<std::vector<int>> matrix = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4},
		{1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
		{1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int startX = 0, startY = 0; // Начальная позиция
	int exitX = 0, exitY = 0;   // Позиция выхода

	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (matrix[i][j] == 0) {
				startX = 11;
				startY = 0;
			}
			else if (matrix[i][j] == 4) {
				exitX = i;
				exitY = j;
			}
		}
	}

	std::vector<std::vector<bool>> visited(ROW, std::vector<bool>(COL, false));

	if (findExit(matrix, startX, startY, exitX, exitY, visited)) {
		std::cout << "Succes!" << std::endl;
	}
	else {
		std::cout << "Fail!" << std::endl;
	}

	// Вывод лабиринта с отмеченным путем
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}