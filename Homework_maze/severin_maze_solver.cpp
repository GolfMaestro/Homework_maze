// severin_maze_solver.cpp
#include "severin_maze_solver.h"

void initSeverinMaze(std::vector<std::vector<int>>& maze, int rows, int cols) {
    // Инициализация лабиринта (ваш код инициализации)
    maze = std::vector<std::vector<int>>(rows, std::vector<int>(cols));
}

void copyMaze(const std::vector<std::vector<int>>& source, std::vector<std::vector<int>>& destination) {
    destination = source;
}

bool isSafe(const std::vector<std::vector<int>>& maze, int row, int col) {
    int m = maze.size();
    int n = maze[0].size();
    return (row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == 0);
}

bool hasDeadEnd(const std::vector<std::vector<int>>& maze, int row, int col) {
    int count = 0;

    if (!isSafe(maze, row + 1, col)) count++;
    if (!isSafe(maze, row - 1, col)) count++;
    if (!isSafe(maze, row, col + 1)) count++;
    if (!isSafe(maze, row, col - 1)) count++;

    return (count >= 3);
}

void fillDeadEnd(std::vector<std::vector<int>>& maze, int row, int col) {
    maze[row][col] = 1;
}

bool solveDeadEndFilling(std::vector<std::vector<int>>& maze) {
    int m = maze.size();
    int n = maze[0].size();

    std::vector<std::vector<int>> severin_maze_copy(m, std::vector<int>(n, 0));
    copyMaze(maze, severin_maze_copy);

    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (hasDeadEnd(severin_maze_copy, i, j)) {
                fillDeadEnd(maze, i, j);
            }
        }
    }

    return false;
}
