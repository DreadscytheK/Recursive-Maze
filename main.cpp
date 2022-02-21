// Read in maze
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include "Maze.h"
#include <cstdlib>

using namespace std;



int main()
{
    //Creates the maze 1 object from the Maze class
    Maze maze1;

    //This function gets the maze and the dimensions of the maze
    maze1.fileSteal();



    //This function figures out the path to the goal
    maze1.RecursiveMazePathDFS();

    //This function prints out the maze
    maze1.printMaze();

system("pause");

    return 0;
}
