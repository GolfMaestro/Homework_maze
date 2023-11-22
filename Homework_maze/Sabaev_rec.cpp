#include <iostream>
#include <vector>
#include "Sabaev_rec.h"
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


vector<vector<int>> maze_copy_rec;
void CopyMaze_Rec(const vector<vector<int>>& maze) {
    maze_copy_rec = maze;
}

// Рекурсивная функция поиска пути в лабиринте
bool findPath(vector<vector<int>>& maze_copy_rec, int x, int y) {
    // Проверка на выход за границы лабиринта
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
        return false;
    }
    // Проверка достижения конечной точки
    if (maze_copy_rec[y][x] == 4) {
        return true;
    }
    // Проверка на стену, уже посещенную клетку или конечную точку
    if (maze_copy_rec[y][x] != 0) {
        return false;
    }
    // Помечаем текущую клетку как посещенную
    maze_copy_rec[y][x] = 2;
    // Рекурсивный вызов для движения вправо, вниз, влево и вверх
    if (findPath(maze_copy_rec, x + 1, y) || findPath(maze_copy_rec, x, y + 1) || findPath(maze_copy_rec, x - 1, y) || findPath(maze_copy_rec, x, y - 1)) {
        return true;
    }
    // Если путь не найден, возвращаемся назад и отмечаем текущую клетку как 0
    maze_copy_rec[y][x] = 0;
    return false;
}


bool maze_main_rec(const vector<vector<int>>& maze) {
    CopyMaze_Rec(maze);
    if (find_path(maze_copy_rec, 0, 10) == true) {
        //printMaze(maze);
        return true;
    }
    else {
        return 0;
    }
}