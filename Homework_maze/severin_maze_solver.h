#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <vector>
#include <stack>

const int ROWS = 12;
const int COLS = 12;

bool isValid(int row, int col);
void printMaze(const std::vector<std::vector<int>>& maze);
void deadEndFilling(std::vector<std::vector<int>>& maze, int startRow, int startCol, int endRow, int endCol);

#endif  // MAZE_SOLVER_H