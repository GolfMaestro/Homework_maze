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

vector<vector<int>> maze;
vector<long long> times;

void calculate_time(vector<vector<int>> maze, int choose) {
    auto start = steady_clock::now();
    switch (choose)
    {
    case 1:
        maze_main_DFS(maze);
        break;
    case 2:
        maze_main_wave(maze);
        break;
    case 3:
        maze_main_wallfollower(maze);
        break;
    case 4:
        maze_main_rec(maze);
        break;
    case 5:
        Tremaux(maze);
        break;
    case 6:
        maze_main_deadend(maze);
        break;
    default:
        break;
    }
    auto finish = steady_clock::now();
    auto duration = duration_cast<microseconds>(finish - start).count();
    times.push_back(duration);
    cout << endl << "Programm work: " << duration << " microseconds." << endl;
}



int main() { // the only one main in project


    int value;
    vector<int> rows_vector;
    //vector<vector<int>> maze;

    ifstream data("data.txt"); // data - 12x12, data2 - 61x62, data3 - 401x401, data4 - another 12x12
    if (!data.is_open()) {
        cout << "file doesn't exist";
        return 0;
    }
    data >> rows;
    data >> columns;
    //if ((typeid(rows).name() != "int") or (typeid(columns).name() != "int")) {
    //    cout << typeid(rows).name();
    //    cout << typeid(columns).name();
    //    cout << "wrong input5";
    //    return 0;
    //}

    if ((rows == 0) or (columns == 0)) {
        cout << "wrong size";
        return 0;
    }

    int count = 1;
    int count_four = 0;
    //cout << rows << endl << columns << endl;
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            data >> value;
            //cout << count << endl;
            if (data.eof() and ((columns * rows) != count)) {
                cout << "not enought values";
                return 0;
            }
            if (value == 0 or value == 1) {
                rows_vector.push_back(value);
                count += 1;
            }
            else if (value == 4) {
                rows_vector.push_back(value);
                count_four += 1;
                count += 1;
            }
            else {
                cout << "wrong maze element";
                return 0;
            }
        }
        maze.push_back(rows_vector);
        rows_vector.clear();
    }

    if (maze[10][0] != 0) {
        cout << "Enter must be on position (10, 0)";
        return 0;
    }
    //cout << count_four << endl;
    if (count_four < 1) {
        cout << "You forgot about exit. Add number 4 to your maze";
        return 0;
    }

    // Check external walls

    for (int i1 = 0; i1 < rows; ++i1) { // columns

        if (maze[i1][0] == 0) {
            if (i1 != 10) {
                cout << "You forgot about external walls";
                return 0;
            }
        }
        if (maze[i1][columns - 1] == 0) {
            cout << "You forgot about external walls";
            return 0;
        }

    }

    for (int i2 = 0; i2 < columns; ++i2) { // rows
        if (maze[0][i2] == 0) {
            cout << "You forgot about external walls";
            return 0;
        }
        if (maze[rows - 1][i2] == 0) {
            cout << "You forgot about external walls";
            return 0;
        }
    }

    cout << endl << "Source maze" << endl;
    printMaze(maze, columns, rows);
    cout << endl;

    //vector<long long> times;
    vector<string> members = { "Akulov", "Naschokin", "Samokrutov", "Sabaev", "Korotkov", "Severin" };

    //cout << "Source maze: " << endl;
    //printMaze(maze, 12, 12);
    cout << "============================" << endl;
    cout << endl;


    cout << "Akulov Vladislav. DFS algorithm solution: ";
    calculate_time(maze, 1);
    printMaze(maze_copy_DFS, columns, rows);
    cout << "============================" << endl;

    cout << "Naschokin Andrey. Wave algorithm solution: ";
    calculate_time(maze, 2);
    printMaze(maze_copy_wave, columns, rows);
    cout << "============================" << endl;

    cout << "Samokrutov Nikolay. Wallfollower algorithm solution: ";
    calculate_time(maze, 3);
    printMaze(maze_copy_wallfollower, columns, rows);
    cout << "============================" << endl;

    cout << "Sabaev Nikita. Recursive algorithm solution: ";
    calculate_time(maze, 4);
    printMaze(maze_copy_rec, columns, rows);
    cout << "============================" << endl;

    cout << "Korotkov Artem. Tremaux algorithm solution: ";
    calculate_time(maze, 5);
    cout << "============================" << endl;

    cout << "Severin Lavrenty. Dead-end algorithm solution: ";
    calculate_time(maze, 6);
    printMaze(maze_copy_deadend, columns, rows);
    cout << "============================" << endl;

    for (int i = 0; i < 6; ++i) {

        cout << members[i] << ": " << times[i] << endl;

    }
    char tttt;
    cout << "Press any button to exit";
    cin >> tttt;

}