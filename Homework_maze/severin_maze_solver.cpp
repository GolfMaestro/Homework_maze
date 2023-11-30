#include "severin_maze_solver.h"
#include <iostream>
#include <vector>
#include <stack>
#include "maze.h"

using namespace std;
vector<vector<int>>maze_copy_deadend;

void CopyMaze_deadend(const vector<vector<int>>& maze) {
    maze_copy_deadend = maze;
}

bool isValid(int row, int col) {
    return (row >= 0) && (row < rows) && (col >= 0) && (col < columns);
}

//void printMaze(const std::vector<std::vector<int>>& maze) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            std::cout << maze[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}

void deadEndFilling(std::vector<std::vector<int>>& maze_copy_deadend, int startRow, int startCol, int endRow, int endCol) {
    std::stack<std::pair<int, int>> pathStack;
    pathStack.push(std::make_pair(startRow, startCol));

    while (!pathStack.empty()) {
        int currentRow = pathStack.top().first;
        int currentCol = pathStack.top().second;

        if (currentRow == endRow && currentCol == endCol) {
            break;
        }

        maze_copy_deadend[currentRow][currentCol] = 2;

        bool foundNextPoint = false;
        for (int i = -1; i <= 1; i += 2) {
            int newRow = currentRow + i;
            int newCol = currentCol + i;

            if (isValid(newRow, currentCol) && maze_copy_deadend[newRow][currentCol] == 0) {
                pathStack.push(std::make_pair(newRow, currentCol));
                foundNextPoint = true;
                break;
            }

            if (isValid(currentRow, newCol) && maze_copy_deadend[currentRow][newCol] == 0) {
                pathStack.push(std::make_pair(currentRow, newCol));
                foundNextPoint = true;
                break;
            }
        }

        if (!foundNextPoint) {
            pathStack.pop();
        }
    }
}


void maze_main_deadend(const vector<vector<int>>& maze) {
    
    CopyMaze_deadend(maze);

    // Новые начальные и конечные точки для примера
    int startRow = 0;
    int startCol = 10;
    int endRow = 1;
    int endCol = 11;

    // Запускаем алгоритм "Dead-end-filling"
    deadEndFilling(maze_copy_deadend, startRow, startCol, endRow, endCol);

}