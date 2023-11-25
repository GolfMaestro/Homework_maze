#pragma once
#include <iostream>
#include <vector>

extern std::vector<std::vector<int>> maze_copy_deadend;

void CopyMaze_deadend(const std::vector<std::vector<int>>& maze);
bool isSafe(int row, int col, const std::vector<std::vector<int>>& maze_copy_deadend, std::vector<std::vector<bool>>& visited);
bool isDeadEnd(int row, int col, const std::vector<std::vector<int>>& maze_copy_deadend);
void fillDeadEnds(std::vector<std::vector<int>>& maze_copy_deadend);
bool maze_main_deadend(const std::vector<std::vector<int>>& maze);
