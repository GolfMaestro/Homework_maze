#pragma once
#include <iostream>
#include <vector>
vector<vector<int>> maze_copy;
extern vector<vector<int>> maze_copy;
void printMaze(const std::vector<std::vector<int>>& maze);
void CopyMaze(const std::vector<std::vector<int>>& maze);
bool isValidMove(const std::vector<std::vector<int>>& maze_copy, int x, int y);
bool findPathDFS(std::vector<std::vector<int>>& maze_copy, int x, int y);


