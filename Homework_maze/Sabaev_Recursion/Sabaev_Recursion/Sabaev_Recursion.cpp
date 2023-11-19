#include <iostream>
#include <vector>

using namespace std;

// Размеры лабиринта
const int ROWS = 12;
const int COLS = 12;

// Функция для вывода лабиринта
void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Рекурсивная функция поиска пути в лабиринте
bool findPath(vector<vector<int>>& maze, int x, int y) {
    // Проверка на выход за границы лабиринта
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
        return false;
    }

    // Проверка достижения конечной точки
    if (maze[y][x] == 4) {
        return true;
    }

    // Проверка на стену, уже посещенную клетку или конечную точку
    if (maze[y][x] != 0) {
        return false;
    }

    // Помечаем текущую клетку как посещенную
    maze[y][x] = 2;

    // Рекурсивный вызов для движения вправо, вниз, влево и вверх
    if (findPath(maze, x + 1, y) || findPath(maze, x, y + 1) || findPath(maze, x - 1, y) || findPath(maze, x, y - 1)) {
        return true;
    }

    // Если путь не найден, возвращаемся назад и отмечаем текущую клетку как 0
    maze[y][x] = 0;

    return false;
}

int main() {
    // Исходная матрица лабиринта
    vector<vector<int>> matrix = {
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

    // Координаты старта
    int startX = 0;
    int startY = 10;

    // Вызываем функцию для поиска пути
    if (findPath(matrix, startX, startY)) {
        cout << "Путь найден:" << endl;
        printMaze(matrix);
    }
    else {
        cout << "Путь не найден." << endl;
    }

    return 0;
}

