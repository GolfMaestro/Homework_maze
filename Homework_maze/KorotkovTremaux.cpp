

#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Tremaux.h"

using namespace std;
int getCorrectValue(vector<vector<int>> x, int row, int  column)
{
    if (row>=0 && column >= 0)
        return x[row][column];
    else
        return -1;
}
int countOfPass(vector<vector<int>> x, int row, int column)
{
    return (getCorrectValue(x,row - 1,column) == 0) + (getCorrectValue(x,row + 1,column) == 0) 
        + (getCorrectValue(x,row,column + 1) == 0) + (getCorrectValue(x,row,column - 1) == 0);
}
bool IsItEnter(vector<vector<int>> x, int row, int column)
{
    return ((getCorrectValue(x,row - 1,column) == 4) || (getCorrectValue(x,row + 1,column) == 4) 
        || (getCorrectValue(x,row,column + 1) == 4) || (getCorrectValue(x,row,column - 1) == 4));
}

string randomCommand(vector<vector<int>> x, int row, int column)
{
    vector <string> possibleCommand;
    if (getCorrectValue(x,row - 1,column) == 0)
        possibleCommand.push_back("up");
    if (getCorrectValue(x,row + 1,column) == 0)
        possibleCommand.push_back("down");
    if (getCorrectValue(x,row,column + 1) == 0)
        possibleCommand.push_back("right");
    if (getCorrectValue(x,row,column - 1) == 0)
        possibleCommand.push_back("left");
    int index = rand() % possibleCommand.size();
    return possibleCommand[index];
}
vector<vector<int>> Tremaux(vector<vector<int>> x)
{
    srand(time(NULL));
    int row = 10;
    int column = 0;
    vector <string> PreviousCommand;
    while (1)
    {
        while (countOfPass(x, row, column) != 0)
        {
            string command;
            command = randomCommand(x, row, column);
            PreviousCommand.push_back(command);
            x[row][column] = 2;
            if (command == "up")
                row -= 1;
            else if (command == "down")
                row += 1;
            else if (command == "left")
                column -= 1;
            else if (command == "right")
                column += 1;
            if (IsItEnter(x, row, column) == true)
            {
                x[row][column] = 2;
                return x;
            }
        }
        while (countOfPass(x, row, column) == 0)
        {
            if (PreviousCommand.size() == 0)
            {
                return vector<vector<int>>{{}};
            }
            x[row][column] = 3;
            if (PreviousCommand[PreviousCommand.size() - 1] == "down")
                row -= 1;
            else if (PreviousCommand[PreviousCommand.size() - 1] == "up")
                row += 1;
            else if (PreviousCommand[PreviousCommand.size() - 1] == "right")
                column -= 1;
            else if (PreviousCommand[PreviousCommand.size() - 1] == "left")
                column += 1;
            PreviousCommand.pop_back();
        }
    }
}
