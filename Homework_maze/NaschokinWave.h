#include <iostream>
#include <vector>
using namespace std;
extern vector<vector<int>> maze_copy_wave;
bool maze_main_wave(const vector<vector<int>>& maze);
void CopyMaze_pledge(const vector<vector<int>>& maze);
bool find_path(vector<vector<int>>& maze_copy_pledge, int x, int y);
