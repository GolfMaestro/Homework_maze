cpp
#include "severin_maze_solver.h"
#include <iostream>

// Пример функции для работы с лабиринтом без использования классов
void processMaze(std::vector<std::vector<int>>& maze) {
    // Ваш код обработки лабиринта
    // Можете вызывать функции из severin_maze_solver.h для решения задачи
}

int main() {
    // Пример использования функций для работы с лабиринтом
    std::vector<std::vector<int>> maze;
    int rows = 5;
    int cols = 5;

    // Инициализация лабиринта
    initSeverinMaze(maze, rows, cols);

    // Обработка лабиринта
    processMaze(maze);

    // Вывод результата
    for (const auto& row : maze) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
