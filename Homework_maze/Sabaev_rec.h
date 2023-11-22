#include <iostream>
#include <vector>
using namespace std;
extern vector<vector<int>> maze_copy_rec;
bool maze_main_rec(const vector<vector<int>>& maze);
bool findPath(vector<vector<int>>& maze_copy_rec, int x, int y);
void CopyMaze_Rec(const vector<vector<int>>& maze);
void printMaze(const vector<vector<int>>& maze);