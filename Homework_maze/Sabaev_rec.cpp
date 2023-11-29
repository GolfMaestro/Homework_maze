#include <iostream>
#include <vector>
#include "Sabaev_rec.h"
#include "maze.h"

using namespace std;
// Ðàçìåðû ëàáèðèíòà
//const int ROWS = 12;
//const int COLS = 12;
// Ôóíêöèÿ äëÿ âûâîäà ëàáèðèíòà
void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> maze_copy_rec;
void CopyMaze_Rec(const vector<vector<int>>& maze) {
    maze_copy_rec = maze;
}

// Ðåêóðñèâíàÿ ôóíêöèÿ ïîèñêà ïóòè â ëàáèðèíòå
bool findPath(vector<vector<int>>& maze_copy_rec, int x, int y) {
    // Ïðîâåðêà íà âûõîä çà ãðàíèöû ëàáèðèíòà
    if (x < 0 || x >= columns || y < 0 || y >= rows) {
        return false;
    }
    // Ïðîâåðêà äîñòèæåíèÿ êîíå÷íîé òî÷êè
    if (maze_copy_rec[y][x] == 4) {
        return true;
    }
    // Ïðîâåðêà íà ñòåíó, óæå ïîñåùåííóþ êëåòêó èëè êîíå÷íóþ òî÷êó
    if (maze_copy_rec[y][x] != 0) {
        return false;
    }
    // Ïîìå÷àåì òåêóùóþ êëåòêó êàê ïîñåùåííóþ
    maze_copy_rec[y][x] = 2;
    // Ðåêóðñèâíûé âûçîâ äëÿ äâèæåíèÿ âïðàâî, âíèç, âëåâî è ââåðõ
    if (findPath(maze_copy_rec, x + 1, y) || findPath(maze_copy_rec, x, y + 1) || findPath(maze_copy_rec, x - 1, y) || findPath(maze_copy_rec, x, y - 1)) {
        return true;
    }
    // Åñëè ïóòü íå íàéäåí, âîçâðàùàåìñÿ íàçàä è îòìå÷àåì òåêóùóþ êëåòêó êàê 0
    maze_copy_rec[y][x] = 0;
    return false;
}


bool maze_main_rec(const vector<vector<int>>& maze) {
    CopyMaze_Rec(maze);
    if (findPath(maze_copy_rec, 0, 10) == true) {
        //printMaze(maze);
        return true;
    }
    else {
        return 0;
    }
}
