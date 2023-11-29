#include <iostream>
#include <vector>
#include "AkulovDFS.h"
#include "maze.h"

using namespace std;
//const int rows = 12;
//const int cols = 12;
vector<vector<int>> maze_copy_DFS;
// ��������� ���������
void printMaze_DFS(const vector<vector<int>>& maze) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
void CopyMaze_DFS(const vector<vector<int>>& maze) {
    maze_copy_DFS = maze;
}
// �������� �������� �� �����
bool isValidMove_DFS(const vector<std::vector<int>>& maze_copy_DFS, int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < columns && maze_copy_DFS[x][y] == 0;
}
// ����� ������ � ������� DFS
bool findPathDFS_DFS(vector<vector<int>>& maze_copy_DFS, int x, int y) {
    if (maze_copy_DFS[x][y] == 4) {
        // ����� ������
        return true;
    }

    if (isValidMove_DFS(maze_copy_DFS, x, y)) {
        // �������� ���������� �����
        maze_copy_DFS[x][y] = 3;

        // ������� ��������� �� ���� ��������� ������������
        if (findPathDFS_DFS(maze_copy_DFS, x + 1, y) || findPathDFS_DFS(maze_copy_DFS, x - 1, y) ||
            findPathDFS_DFS(maze_copy_DFS, x, y + 1) || findPathDFS_DFS(maze_copy_DFS, x, y - 1)) {
            // �������� ������ ��� ����� ����
            maze_copy_DFS[x][y] = 2;
            return true;
        }

        // ���� �� ������� ������ ��� ����, �� ������������ �����
        maze_copy_DFS[x][y] = 0;
    }

    return false;
}

void maze_main_DFS(const vector<vector<int>>& maze) {
    // ������������� ���������

    CopyMaze_DFS(maze);


    // ��������� ����� (10, 0)
    findPathDFS_DFS(maze_copy_DFS, 10, 0);



}