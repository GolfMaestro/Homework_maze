#include <iostream>
#include <array>
#include "mazeWave.h"

using namespace std;

#define NROWS 12
#define MCOLS 12

int find_path(int maze[12][12], int x, int y) {
    if (x < 0 || x > MCOLS - 1 || y < 0 || y > NROWS - 1) return false;
    if (maze[y][x] == 4) return true;
    if (maze[y][x] != 0) return false;
    maze[y][x] = 2;
    if (find_path(maze, x, y - 1) == true) return true;
    if (find_path(maze, x + 1, y) == true) return true;
    if (find_path(maze, x, y + 1) == true) return true;
    if (find_path(maze, x - 1, y) == true) return true;
    return false;
}
int wave(int maze[12][12]) {
    if (find_path(maze, 0, 10) == true) {
        printf("MAZE:\n");
        for (int i = 0; i < NROWS; i++) {
            for (int j = 0; j < MCOLS; j++)
                cout << maze[i][j] << " ";
            cout << endl;
        }
    }
    else {
        return 0;       
    }
}


