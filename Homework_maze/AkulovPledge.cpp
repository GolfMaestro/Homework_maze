#include <iostream>
#include <vector>
#include "AkulovPledge.h"

using namespace std;
const int rows = 12;
const int cols = 12;
vector<vector<int>> maze_copy_pledge;
// Функция для печати лабиринта
void printMaze_pledge(const vector<vector<int>>& maze) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
void CopyMaze_pledge(const vector<vector<int>>& maze) {
    maze_copy_pledge = maze;
}
// Функция для проверки возможности движения в заданной точке
bool isValidMove_pledge(const vector<std::vector<int>>& maze_copy_pledge, int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze_copy_pledge[x][y] == 0;
}
// Функция для поиска пути в лабиринте с использованием DFS
bool findPathDFS_pledge(vector<vector<int>>& maze_copy_pledge, int x, int y) {
    if (maze_copy_pledge[x][y] == 4) {
        // Достигнут выход из лабиринта
        return true;
    }

    if (isValidMove_pledge(maze_copy_pledge, x, y)) {
        // Помечаем текущую ячейку как посещенную
        maze_copy_pledge[x][y] = 3;

        // Пробуем двигаться во всех возможных направлениях
        if (findPathDFS_pledge(maze_copy_pledge, x + 1, y) || findPathDFS_pledge(maze_copy_pledge, x - 1, y) ||
            findPathDFS_pledge(maze_copy_pledge, x, y + 1) || findPathDFS_pledge(maze_copy_pledge, x, y - 1)) {
            // Если путь найден, помечаем ячейку как часть пути
            maze_copy_pledge[x][y] = 2;
            return true;
        }

        // Если из текущей ячейки нет пути, возвращаемся назад
        maze_copy_pledge[x][y] = 0;
    }

    return false;
}

void maze_main_pledge(const vector<vector<int>>& maze) {
    // Инициализация лабиринта

    CopyMaze_pledge(maze);
    
   
    // Начинаем поиск пути с точки входа (10, 0)
    findPathDFS_pledge(maze_copy_pledge, 10, 0);
 
       
    
}
