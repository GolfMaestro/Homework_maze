#include <iostream>
#include <vector>

#define ROW 12
#define COL 12

using namespace std;

vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
vector<vector<int>> maze_copy_wallfollower;

void CopyMaze_wallfollower(const vector<vector<int>>& maze) {
    maze_copy_wallfollower = maze;
}

bool isSafe(int row, int col, const vector<vector<int>>& maze_copy_wallfollower, vector<vector<bool>>& visited) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (maze_copy_wallfollower[row][col] != 1) && !visited[row][col];
}

// Новая функция для проверки, является ли клетка тупиковой
bool isDeadEnd(int row, int col, const vector<vector<int>>& maze_copy_wallfollower) {
    int wallCount = 0;
    int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    for (int i = 0; i < 4; ++i) {
        int nextDirX = row + directions[i][0];
        int nextDirY = col + directions[i][1];

        if (nextDirX >= 0 && nextDirX < ROW && nextDirY >= 0 && nextDirY < COL && maze_copy_wallfollower[nextDirX][nextDirY] == 1) {
            wallCount++;
        }
    }

    return wallCount >= 3; // Клетка считается тупиковой, если у неё 3 или более стен
}

bool findExit(vector<vector<int>>& maze_copy_wallfollower, int row, int col, int exitRow, int exitCol, vector<vector<bool>>& visited) {
    if (row == exitRow && col == exitCol) {
        return true;
    }

    visited[row][col] = true;

    int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    for (int i = 0; i < 4; ++i) {
        int nextDirX = row + directions[i][0];
        int nextDirY = col + directions[i][1];

        if (isSafe(nextDirX, nextDirY, maze_copy_wallfollower, visited)) {
            maze_copy_wallfollower[nextDirX][nextDirY] = 2;

            if (findExit(maze_copy_wallfollower, nextDirX, nextDirY, exitRow, exitCol, visited)) {
                return true;
            }
        }
    }

    if (isDeadEnd(row, col, maze_copy_wallfollower)) {
        maze_copy_wallfollower[row][col] = 1; // Помечаем тупиковые клетки стеной
    }

    return false;
}

bool maze_main_wallfollower(const vector<vector<int>>& maze) {
    CopyMaze_wallfollower(maze);
    int startX = 0, startY = 0;
    int exitX = 0, exitY = 0;

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (maze[i][j] == 0) {
                startX = i;
                startY = j;
            }
            else if (maze[i][j] == 4) {
                exitX = i;
                exitY = j;
            }
        }
    }

    if (findExit(maze_copy_wallfollower, startX, startY, exitX, exitY, visited)) {
        cout << "Успех!" << endl;
    }
    else {
        cout << "Не удалось!" << endl;
    }

    // Вывод лабиринта с отмеченным путем
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << maze_copy_wallfollower[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
