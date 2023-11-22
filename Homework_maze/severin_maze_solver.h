// severin_maze_solver.h
#ifndef SEVERIN_MAZE_SOLVER_H
#define SEVERIN_MAZE_SOLVER_H

#include <vector>

class SeverinMaze {
public:
    SeverinMaze(int rows, int cols);
    void copyMaze(std::vector<std::vector<int>>& destination) const;
    bool solveDeadEndFilling();

private:
    int m;
    int n;
    std::vector<std::vector<int>> maze;

    bool isSafe(int row, int col) const;
    bool hasDeadEnd(int row, int col) const;
    void fillDeadEnd(int row, int col);
};

#endif // SEVERIN_MAZE_SOLVER_H
