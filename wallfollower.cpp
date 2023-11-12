#include <iostream>
#include <windows.h>
const int MazeWidth = 30;
const int MazeHeight = 20;
const char MazeExit = '$';
const char Wall = '#';
const char Free = ' ';
const unsigned char SomeDude = 254;
COORD MazeExitCoords;
COORD StartingPoint;

using namespace std;
char Maze[MazeHeight][MazeWidth];




void FillDaMaze() {

    MazeExitCoords.X = MazeWidth - 20;
    MazeExitCoords.Y = 2;
    StartingPoint.X = 3;
    StartingPoint.Y = MazeHeight - 3;

    for (int i = 0; i < MazeHeight; i++) {

        for (int ii = 0; ii < MazeWidth; ii++) {

            if (i == 0 || i == MazeHeight - 1 || ii == 0 || ii == MazeWidth - 1) {
                Maze[i][ii] = Wall;
            }
            else {
                Maze[i][ii] = Free;
            }

            if (i == MazeExitCoords.Y && ii == MazeExitCoords.X) {
                Maze[i][ii] = MazeExit;
            }
            else if (i == StartingPoint.Y && ii == StartingPoint.X) {
                Maze[i][ii] = SomeDude;
            }
        }
    }
}
void PrintDaMaze(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    for (int i = 0; i < MazeHeight; i++) {

        for (int ii = 0; ii < MazeWidth; ii++) {

            cout << Maze[i][ii];
        }
        cout << endl;
    }
}
void FindYourWayThroughTheMaze() {



    if (Maze[StartingPoint.Y + 1][StartingPoint.X] != Wall && Maze[StartingPoint.Y + 1][StartingPoint.X] != SomeDude) {
        StartingPoint.Y++;



    }
    else if (Maze[StartingPoint.Y][StartingPoint.X + 1] != Wall && Maze[StartingPoint.Y][StartingPoint.X + 1] != SomeDude) {
        StartingPoint.X++;



    }
    else if (Maze[StartingPoint.Y - 1][StartingPoint.X] != Wall && Maze[StartingPoint.Y - 1][StartingPoint.X] != SomeDude) {
        StartingPoint.Y--;





    }
    else if (Maze[StartingPoint.Y][StartingPoint.X - 1] != Wall && Maze[StartingPoint.Y][StartingPoint.X - 1] != SomeDude) {
        StartingPoint.X--;



    }


    Maze[StartingPoint.Y][StartingPoint.X] = SomeDude;

}
int worck() {

    FillDaMaze();
    PrintDaMaze(10);
    while (StartingPoint.X != MazeExitCoords.X || StartingPoint.Y != MazeExitCoords.Y) {
        FindYourWayThroughTheMaze();
        system("CLS");
        PrintDaMaze(10);
        Sleep(50);
    }

