// maze_solver.cpp

#include "maze_solver.h"

// Конструктор для инициализации лабиринта
Maze::Maze(int rows, int cols) : m(rows), n(cols), maze(std::vector<std::vector<int>>(m, std::vector<int>(n))) {}

// Функция для проверки, является ли клетка допустимой для движения
bool Maze::isSafe(int row, int col) const {
    return (row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == 0);
}

// Функция для вывода лабиринта
void Maze::printMaze() const {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для поиска выхода из лабиринта
bool Maze::findExit(int row, int col) {
    // Реализация поиска выхода (аналогично предыдущему коду)
    // ...

    return false;
}
