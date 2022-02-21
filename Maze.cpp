// Read in maze
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Maze.h"

using namespace std;

void Maze::printMaze()
{
    for (int i=0; i<mRow; i++) {
        for (int j=0; j<mCol; j++) {
            if(maze[i][j]=='-') {
                maze[i][j]='.';
            }
            cout << maze[i][j];
        }
        cout << endl;
    }
}



int Maze::RecursiveMazePathDFS()
{
    //system("CLS");
   // for (int i=0; i<mRow; i++){
 //for (int j=0; j<mCol; j++){
  //   cout << maze[i][j];}
   //cout << endl;}
    //al_rest(0.1);
    //system("pause");


    //Every if statement here checks if the character '.' or 'G' is in the space it is looking at. Each if statement
    //is looking in a different direction, and if an if statement meets it conditions, it then checks if the spot is
    //'G' and if it is then it exits the function, if it is not then it changes the character of the spot it is going to
    //to '+' and then returns itself with the coordinates changed based on the direction.

    //Goes East
    if(maze[x][y+1]=='.'||maze[x][y+1]=='G') {
        //Checks if G is the character in the specified direction
        if(x==gx&&y+1==gy) {
            return 0;
        }
        //Changes the character in the specified direction to '+'
        maze[x][y+1]='+';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        y++;
        return RecursiveMazePathDFS();
    }
    //Goes West
    else if(maze[x][y-1]=='.'||maze[x][y-1]=='G') {
        //Checks if G is the character in the specified direction
        if(x==gx&&y-1==gy) {
            return 0;
        }
        //Changes the character in the specified direction to '+'
        maze[x][y-1]='+';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        y--;
        return RecursiveMazePathDFS();
    }
    //Goes South
    else if(maze[x+1][y]=='.'||maze[x+1][y]=='G') {
        //Checks if G is the character in the specified direction
        if(x+1==gx&&y==gy) {
            return 0;
        }
        //Changes the character in the specified direction to '+'
        maze[x+1][y]='+';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        x++;
        return RecursiveMazePathDFS();
    }
    //Goes North
    else if(maze[x-1][y]=='.'||maze[x-1][y]=='G') {
        //Checks if G is the character in the specified direction
        if(x-1==gx&&y==gy) {
            return 0;
        }
        //Changes the character in the specified direction to '+'
        maze[x-1][y]='+';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        x--;
        return RecursiveMazePathDFS();
    }

    //These if statements only work if there is no new direction. They activate depending on if there is a
    //'+' character in any of the specified directions. They then put a '-' character where they are going
    //and then run the RecursiveMazePathDFS function in the direction they are going. This is how the function
    //backtracks.

    //Goes West
    if(maze[x][y-1]=='+') {
        //Changes the character in the specified direction to '-'
        maze[x][y]='-';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        y--;
        return RecursiveMazePathDFS();
    }
    //Goes South
    else if(maze[x+1][y]=='+') {
        //Changes the character in the specified direction to '-'
        maze[x][y]='-';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        x++;
        return RecursiveMazePathDFS();
    }
    //Goes East
    else if(maze[x][y+1]=='+') {
        //Changes the character in the specified direction to '-'
        maze[x][y]='-';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        y++;
        return RecursiveMazePathDFS();
    }
    //Goes North
    else if(maze[x-1][y]=='+') {
        //Changes the character in the specified direction to '-'
        maze[x][y]='-';
        //Returns RecursiveMazePathDFS with all the needed variables, except it changes the x and y variables
        //Based on the specified direction
        x--;
        return RecursiveMazePathDFS();
    }
}



///File steal function gets the maze and its dimensions
int Maze::fileSteal()
{
    //Declaring variables
    string row;

    //Gets the text file and gives an error if it does not open
    ifstream fin("maze.txt");
    if (!fin.is_open()) {
        cout << "maze.txt not found" << endl;
        return 1;
    }

    //Find out the size
    while (!fin.eof()) {
        fin >> row;
        mRow++;
    }
    mCol = row.length();

    //Go to beginning of file
    fin.clear(); //Clear bad state after eof
    fin.seekg( 0 );

    //Resize maze
    maze.resize(mRow);
    for (int i=0; i<mRow; i++)
        maze[i].resize(mCol);

    //Read maze (add finding S and G)
    for (int i=0; i<mRow; i++) {
        for (int j=0; j<mCol; j++) {
            fin >> maze[i][j];
            if(maze[i][j]=='S') {
                y = i;
                x = j;
            }
            if(maze[i][j]=='G') {
                gx = i;
                gy = j;
            }
        }
    }
    fin.close();

    return 0;
}

