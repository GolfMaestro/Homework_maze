#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "AkulovDFS.h"
#include "NaschokinWave.h"
#include "SamokrutovWallFollower.h"
#include "Sabaev_rec.h"
#include "Tremaux.h"
#include "severin_maze_solver.h"

using namespace std;
using namespace chrono;


//vector<vector<int>> maze = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//                {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4},
//                {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
//                {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
//                {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
//                {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
//                {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
//                {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
//                {1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
//                {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
//                {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
//                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };


void printMaze(const vector<vector<int>>& maze, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int rows;
int columns;


int main() { // the only one main in project


    int value;
    vector<int> rows_vector;
    vector<vector<int>> maze;

    ifstream data("data.txt"); // data - 12x12, data2 - 61x62, data3 - 401x401, data4 - another 12x12
    data >> rows;
    data >> columns;

    cout << rows << endl << columns << endl;

    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            data >> value;
            rows_vector.push_back(value);
        }
        maze.push_back(rows_vector);
        rows_vector.clear();
    }

    cout << endl << "Source maze" << endl;
    printMaze(maze, columns, rows);
    cout << endl;

    vector<long long> times;
    vector<string> members = { "Akulov", "Naschokin", "Samokrutov", "Sabaev", "Korotkov", "Severin" };

    //cout << "Source maze: " << endl;
    //printMaze(maze, 12, 12);
    cout << "============================" << endl;
    cout << endl;


    cout << "Akulov Vladislav. Pledge algorithm solution: " << endl;
    auto start = steady_clock::now();
    maze_main_DFS(maze);
    auto finish = steady_clock::now();
    auto duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    printMaze(maze_copy_DFS, columns, rows);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;


    cout << "Naschokin Andrey. Wave algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_wave(maze);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    printMaze(maze_copy_wave, columns, rows);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Samokrutov Nikolay. Wallfollower algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_wallfollower(maze);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    printMaze(maze_copy_wallfollower, columns, rows);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Sabaev Nikita. Recursive algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_rec(maze);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    printMaze(maze_copy_rec, columns, rows);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Korotkov Artem. Tremaux algorithm solution: " << endl;
    start = steady_clock::now();
    Tremaux(maze);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    printMaze(Tremaux(maze), columns, rows);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Severin Lavrenty. Dead-end algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_deadend(maze);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    printMaze(maze_copy_deadend, columns, rows);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    for (int i = 0; i < 6; ++i) {

        cout << members[i] << ": " << times[i] << endl;

    }
    char tttt;
    cout << "Press any button to exit";
    cin >> tttt;

}