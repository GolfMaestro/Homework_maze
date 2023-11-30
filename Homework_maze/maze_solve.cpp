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
#include <stdlib.h>
#include <typeinfo>

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

void inputint(int& x) {

    cin >> x;
    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
}

int main() { // the only one main in project


    int value;
    vector<int> rows_vector;
    vector<vector<int>> maze;

    ifstream data("data.txt");
    if (!data.is_open()) {
        cout << "file doesn't exist";
        return 0;
    }
    data >> rows;
    data >> columns;
    if ((typeid(rows).name() != "int") or (typeid(columns).name() != "int")) {
        cout << typeid(rows).name();
        cout << typeid(columns).name();
        cout << "wrong input5";
        return 0;
    }
    int count = 0;
    cout << rows << endl << columns << endl;

    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            data >> value;
            if (data.eof()) {
                cout << "wrong input0";
                return 0;
            }
            if (typeid(value).name() != "int") {
                cout << "wrong input1";
                return 0;
            }
            if (value == 0 or value == 1 or value == 4) {
                rows_vector.push_back(value);
                count += 1;
            }
            else {
                cout << "wrong input2";
                return 0;
            }
        }
        maze.push_back(rows_vector);
        rows_vector.clear();
    }
    cout << count;


    cout << endl;
    printMaze(maze);
    cout << endl;

    vector<long long> times;
    vector<string> members = { "Akulov", "Naschokin", "Samokrutov", "Sabaev", "Korotkov", "Severin" };

    //cout << "Source maze: " << endl;
    //printMaze(maze, 12, 12);
    cout << "============================" << endl;
    cout << endl;

    cout << "Akulov Vladislav. DFS algorithm solution: " << endl;
    auto start = steady_clock::now();
    maze_main_DFS(maze);
    printMaze(maze_copy_DFS, columns, rows);
    auto finish = steady_clock::now();
    auto duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Naschokin Andrey. Wave algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_wave(maze);
    printMaze(maze_copy_wave, columns, rows);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Samokrutov Nikolay. Wallfollower algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_wallfollower(maze);
    printMaze(maze_copy_wallfollower, columns, rows);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Sabaev Nikita. Recursive algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_rec(maze);
    printMaze(maze_copy_rec, columns, rows);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Korotkov Artem. Tremaux algorithm solution: " << endl;
    start = steady_clock::now();
    printMaze(Tremaux(maze), columns, rows);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
    cout << "============================" << endl;
    cout << endl;

    cout << "Severin Lavrenty. Dead-end algorithm solution: " << endl;
    start = steady_clock::now();
    maze_main_deadend(maze);
    printMaze(maze_copy_deadend, columns, rows);
    finish = steady_clock::now();
    duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
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
