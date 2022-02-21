#include <iostream>

using namespace std;

class Maze{
public:
    int fileSteal();
    int RecursiveMazePathDFS();
    void printMaze();

private:
    vector<vector <char> > maze;
    int mRow = 0;
    int mCol = 0;
    int x, y;
    int gx, gy;

};
