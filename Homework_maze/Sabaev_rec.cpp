#include <iostream>
#include <vector>
#include "Sabaev_rec.h"
using namespace std;
// ������� ���������
const int ROWS = 12;
const int COLS = 12;
// ������� ��� ������ ���������
void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> maze_copy_rec;
void CopyMaze_Rec(const vector<vector<int>>& maze) {
    maze_copy_rec = maze;
}

// ����������� ������� ������ ���� � ���������
bool findPath(vector<vector<int>>& maze_copy_rec, int x, int y) {
    // �������� �� ����� �� ������� ���������
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
        return false;
    }
    // �������� ���������� �������� �����
    if (maze_copy_rec[y][x] == 4) {
        return true;
    }
    // �������� �� �����, ��� ���������� ������ ��� �������� �����
    if (maze_copy_rec[y][x] != 0) {
        return false;
    }
    // �������� ������� ������ ��� ����������
    maze_copy_rec[y][x] = 2;
    // ����������� ����� ��� �������� ������, ����, ����� � �����
    if (findPath(maze_copy_rec, x + 1, y) || findPath(maze_copy_rec, x, y + 1) || findPath(maze_copy_rec, x - 1, y) || findPath(maze_copy_rec, x, y - 1)) {
        return true;
    }
    // ���� ���� �� ������, ������������ ����� � �������� ������� ������ ��� 0
    maze_copy_rec[y][x] = 0;
    return false;
}


bool maze_main_rec(const vector<vector<int>>& maze) {
    CopyMaze_Rec(maze);
    if (find_path(maze_copy_rec, 0, 10) == true) {
        //printMaze(maze);
        return true;
    }
    else {
        return 0;
    }
}