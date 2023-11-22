// severin_maze_solver.h
#ifndef SEVERIN_MAZE_SOLVER_H
#define SEVERIN_MAZE_SOLVER_H

#include <vector>

void initSeverinMaze(std::vector<std::vector<int>>& maze, int rows, int cols);
void copyMaze(const std::vector<std::vector<int>>& source, std::vector<std::vector<int>>& destination);
bool solveDeadEndFilling(std::vector<std::vector<int>>& maze);

bool isSafe(const std::vector<std::vector<int>>& maze, int row, int col);
bool hasDeadEnd(const std::vector<std::vector<int>>& maze, int row, int col);
void fillDeadEnd(std::vector<std::vector<int>>& maze, int row, int col);

#endif // SEVERIN_MAZE_SOLVER_H
