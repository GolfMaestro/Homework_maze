#pragma once
#include <iostream>
#include <vector>
using namespace std;
extern vector<vector<int>> maze_copy_wallfollower;
void CopyMaze_wallfollower(const vector<vector<int>>& maze);
bool isSafe(int row, int col, const vector<vector<int>>& maze_copy_wallfollower, vector<vector<bool>>& visited);
bool findExit(vector<vector<int>>& maze_copy_wallfollower, int row, int col, int exitRow, int exitCol,
	std::vector<std::vector<bool>>& visited);
bool maze_main_wallfollower(const vector<vector<int>>& maze);