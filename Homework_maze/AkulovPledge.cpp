#include <iostream>
#include <vector>
#include "AkulovPledge.h"

using namespace std;
const int rows = 12;
const int cols = 12;
vector<vector<int>> maze_copy_pledge;
// ������� ��� ������ ���������
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
// ������� ��� �������� ����������� �������� � �������� �����
bool isValidMove_pledge(const vector<std::vector<int>>& maze_copy_pledge, int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze_copy_pledge[x][y] == 0;
}
// ������� ��� ������ ���� � ��������� � �������������� DFS
bool findPathDFS_pledge(vector<vector<int>>& maze_copy_pledge, int x, int y) {
    if (maze_copy_pledge[x][y] == 4) {
        // ��������� ����� �� ���������
        return true;
    }

    if (isValidMove_pledge(maze_copy_pledge, x, y)) {
        // �������� ������� ������ ��� ����������
        maze_copy_pledge[x][y] = 3;

        // ������� ��������� �� ���� ��������� ������������
        if (findPathDFS_pledge(maze_copy_pledge, x + 1, y) || findPathDFS_pledge(maze_copy_pledge, x - 1, y) ||
            findPathDFS_pledge(maze_copy_pledge, x, y + 1) || findPathDFS_pledge(maze_copy_pledge, x, y - 1)) {
            // ���� ���� ������, �������� ������ ��� ����� ����
            maze_copy_pledge[x][y] = 2;
            return true;
        }

        // ���� �� ������� ������ ��� ����, ������������ �����
        maze_copy_pledge[x][y] = 0;
    }

    return false;
}

void maze_main_pledge(const vector<vector<int>>& maze) {
    // ������������� ���������

    CopyMaze_pledge(maze);
    
   
    // �������� ����� ���� � ����� ����� (10, 0)
    findPathDFS_pledge(maze_copy_pledge, 10, 0);
 
       
    
}
