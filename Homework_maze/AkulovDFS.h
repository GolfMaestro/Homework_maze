#pragma once
#include <iostream>
#include <vector>
using namespace std;
extern vector<vector<int>> maze_copy_DFS;
void printMaze_DFS(const vector<vector<int>>& maze);
void CopyMaze_DFS(const vector<vector<int>>& maze);
bool isValidMove_DFS(const vector<vector<int>>& maze_copy_DFS, int x, int y);
bool findPath_DFS(std::vector<vector<int>>& maze_copy_DFS, int x, int y);
void maze_main_DFS(const vector<vector<int>>& maze);
