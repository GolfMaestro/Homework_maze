#pragma once
#include <iostream>
#include <vector>
using namespace std;
extern vector<vector<int>> maze_copy_pledge;
void printMaze_pledge(const vector<vector<int>>& maze);
void CopyMaze_pledge(const vector<vector<int>>& maze);
bool isValidMove_pledge(const vector<vector<int>>& maze_copy_pledge, int x, int y);
bool findPathDFS_pledge(std::vector<vector<int>>& maze_copy_pledge, int x, int y);
void maze_main_pledge(const vector<vector<int>>& maze);
