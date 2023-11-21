#include <iostream>
#include <vector>
#include "AkulovPledge.h"

using namespace std;
const int rows = 12;
const int cols = 12;
vector<vector<int>> maze_copy;
// ������� ��� ������ ���������
void printMaze(const std::vector<std::vector<int>>& maze) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << maze[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void CopyMaze(const std::vector<std::vector<int>>& maze) {
    maze_copy = maze;
}
// ������� ��� �������� ����������� �������� � �������� �����
bool isValidMove(const std::vector<std::vector<int>>& maze_copy, int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze_copy[x][y] == 0;
}
// ������� ��� ������ ���� � ��������� � �������������� DFS
bool findPathDFS(std::vector<std::vector<int>>& maze_copy, int x, int y) {
    if (maze_copy[x][y] == 4) {
        // ��������� ����� �� ���������
        return true;
    }

    if (isValidMove(maze_copy, x, y)) {
        // �������� ������� ������ ��� ����������
        maze_copy[x][y] = 2;

        // ������� ��������� �� ���� ��������� ������������
        if (findPathDFS(maze_copy, x + 1, y) || findPathDFS(maze_copy, x - 1, y) ||
            findPathDFS(maze_copy, x, y + 1) || findPathDFS(maze_copy, x, y - 1)) {
            // ���� ���� ������, �������� ������ ��� ����� ����
            maze_copy[x][y] = 3;
            return true;
        }

        // ���� �� ������� ������ ��� ����, ������������ �����
        maze_copy[x][y] = 0;
    }

    return false;
}

//int main() {
//    // ������������� ���������
//
//    std::vector<std::vector<int>> maze = {
//                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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
//                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//    };
//
//    CopyMaze(maze);
//
//    std::cout << "Maze before the way:" << std::endl;
//    printMaze(maze);
//
//    // �������� ����� ���� � ����� ����� (10, 0)
//    if (findPathDFS(maze_copy, 10, 0)) {
//        std::cout << "\nShow me the way:" << std::endl;
//        printMaze(maze);
//        cout << endl << "===============================" << endl;
//        printMaze(maze_copy);
//    }
//    else {
//        std::cout << "\nThere is no way." << std::endl;
//    }
//
//    return 0;
//}

//int* ReturnCopyMaze(std::vector<std::vector<int>>& maze) {
//    if (findPathDFS(maze_copy, 10, 0)) {
//        std::cout << "\nShow me the way:" << std::endl;
//        //printMaze(maze);
//        //cout << endl << "===============================" << endl;
//        //printMaze(maze_copy);
//    }
//    //else {
//      //  std::cout << "\nThere is no way." << std::endl;
//    //}
//
//    return ;
//}