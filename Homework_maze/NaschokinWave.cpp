#include <iostream>
#include <array>
#include <vector>
#include "NaschokinWave.h"

using namespace std;

#define NROWS 12
#define MCOLS 12
vector<vector<int>> maze_copy_wave;
void CopyMaze_wave(const vector<vector<int>>& maze) {
    maze_copy_wave = maze;
}

bool find_path(vector<vector<int>>& maze_copy_wave, int x, int y) {
    if (x < 0 || x > MCOLS - 1 || y < 0 || y > NROWS - 1) return false;
    if (maze_copy_wave[y][x] == 4) return true;
    if (maze_copy_wave[y][x] != 0) return false;
    maze_copy_wave[y][x] = 2;
    if (find_path(maze_copy_wave, x, y - 1) == true) return true;
    if (find_path(maze_copy_wave, x + 1, y) == true) return true;
    if (find_path(maze_copy_wave, x, y + 1) == true) return true;
    if (find_path(maze_copy_wave, x - 1, y) == true) return true;
    return false;
}
bool maze_main_wave(const vector<vector<int>>& maze) {
    CopyMaze_wave(maze);
    if (find_path(maze_copy_wave, 0, 10) == true) {
        /*printf("MAZE:\n");
        for (int i = 0; i < NROWS; i++) {
            for (int j = 0; j < MCOLS; j++)
                cout << maze[i][j] << " ";
            cout << endl;
        }*/
        return true;
    }
    else {
        return 0;       
    }
}
