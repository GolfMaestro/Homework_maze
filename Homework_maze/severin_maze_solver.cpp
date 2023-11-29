#include "maze_solver.h"
#include <iostream>

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

void printMaze(const std::vector<std::vector<int>>& maze) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void deadEndFilling(std::vector<std::vector<int>>& maze, int startRow, int startCol, int endRow, int endCol) {
    std::stack<std::pair<int, int>> pathStack;
    pathStack.push(std::make_pair(startRow, startCol));

    while (!pathStack.empty()) {
        int currentRow = pathStack.top().first;
        int currentCol = pathStack.top().second;

        if (currentRow == endRow && currentCol == endCol) {
            break;
        }

        maze[currentRow][currentCol] = 2;

        bool foundNextPoint = false;
        for (int i = -1; i <= 1; i += 2) {
            int newRow = currentRow + i;
            int newCol = currentCol + i;

            if (isValid(newRow, currentCol) && maze[newRow][currentCol] == 0) {
                pathStack.push(std::make_pair(newRow, currentCol));
                foundNextPoint = true;
                break;
            }

            if (isValid(currentRow, newCol) && maze[currentRow][newCol] == 0) {
                pathStack.push(std::make_pair(currentRow, newCol));
                foundNextPoint = true;
                break;
            }
        }

        if (!foundNextPoint) {
            pathStack.pop();
        }
    }
}