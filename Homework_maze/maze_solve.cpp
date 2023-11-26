#include <iostream>
#include <vector>
#include <chrono>
#include "AkulovPledge.h"
#include "NaschokinWave.h"
#include "SamokrutovWallFollower.h"
#include "Sabaev_rec.h"
#include "Tremaux.h"
#include "severin_maze_solver.h"

using namespace std;
using namespace chrono;

vector<vector<int>> maze = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };


void printMaze(const vector<vector<int>>& maze, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}


int main() { // the only one main in project

    cout << "Source maze: " << endl;
    printMaze(maze, 12, 12);
    cout << "============================" << endl;
    cout << endl;

    cout << "Akulov Vladislav. Pledge algorithm solution: " << endl;
    auto start = steady_clock::now();
    maze_main_pledge(maze);
    printMaze(maze_copy_pledge, 12, 12);
    auto finish = steady_clock::now();
    auto duration = duration_cast<microseconds>(finish - start).count();
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Andrey Naschokin. Wave algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_wave(maze);
    printMaze(maze_copy_wave, 12, 12);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Nikolay Samokrutov. Wallfollower algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_wallfollower(maze);
    printMaze(maze_copy_wallfollower, 12, 12);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Sabaev Nikita. Recursive algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_rec(maze);
    printMaze(maze_copy_rec, 12, 12);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Korotkov Artem. Tremaux algorithm solution: " << endl;
    start = steady_clock::now();
    printMaze(Tremaux(maze), 12, 12);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Severin Lavrenty. Dead-end algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_deadend(maze);
    printMaze(maze_copy_deadend, 12, 12);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

}
