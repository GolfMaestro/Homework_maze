// severin_maze_solver.cpp
#include "severin_maze_solver.h"

SeverinMaze::SeverinMaze(int rows, int cols) : m(rows), n(cols), maze(std::vector<std::vector<int>>(m, std::vector<int>(n))) {
    // Инициализация лабиринта (ваш код инициализации)
}

void SeverinMaze::copyMaze(std::vector<std::vector<int>>& destination) const {
    destination = maze;
}

bool SeverinMaze::isSafe(int row, int col) const {
    return (row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == 0);
}

bool SeverinMaze::hasDeadEnd(int row, int col) const {
    // Проверка, является ли текущая клетка тупиковой
    int count = 0;

    // Подсчет количества соседей, которые являются стенами
    if (!isSafe(row + 1, col)) count++;
    if (!isSafe(row - 1, col)) count++;
    if (!isSafe(row, col + 1)) count++;
    if (!isSafe(row, col - 1)) count++;

    return (count >= 3); // Вернуть true, если у текущей клетки три или более стенных соседа
}

void SeverinMaze::fillDeadEnd(int row, int col) {
    // Заполнение тупиковой клетки
    maze[row][col] = 1;
}

bool SeverinMaze::solveDeadEndFilling() {
    std::vector<std::vector<int>> severin_maze_copy(m, std::vector<int>(n, 0)); // Создание копии лабиринта
    copyMaze(severin_maze_copy);

    // Алгоритм заполнения тупиков
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (hasDeadEnd(i, j)) {
                fillDeadEnd(i, j);
            }
        }
    }

    // Возвращаем true, если найден выход после заполнения тупиков
    return false;
}
