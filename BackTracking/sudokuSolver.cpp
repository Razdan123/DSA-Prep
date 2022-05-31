//Sudoku Solver
/*
We will be given a 9*9 matrix with some boxes filled as '0'. We need to consider those places as empty
and fill those places with digits from 1-9 considering the rules of a general SUDOKU.

APPROACH -->

For checking the valid number , Condition to follow :-
    1. No two same numbers can be present in the same row,              |
    2. No two same numbers can be present in the same column,           |---> Make a seperate function to check the validation
    3 No two same numbers can be present in the box of each 3*3 matrix, |

In solve function just go to each box check weather it has zero if zero, then run a loop from 1-9 and
check for the valid entry.If valid enter the data if nothing is valid BACKTRACK.

*/
#include<bits/stdc++.h>

using namespace std;

#define N 9

bool isSafe(int row, int col, int grid[N][N],int val){
    //checking row
    for(int i=0; i<N; i++){
        if(grid[row][i]==val){
            return false;
        }
    
    //checking col
        if(grid[i][col]==val){
            return false;
        }
    

    //Checking the box
        if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }

    return true;
}


bool solve(int grid[N][N]){    //--> Array by default by reference hi pass hota h
    
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){

            //Cell empty
            if(grid[row][col] == 0){
                for(int i = 1; i <= 9; i++){
                    if(isSafe(row,col,grid,i)){
                        grid[row][col] = i;
                        //recursive call
                        bool aageSolveKrdo = solve(grid);
                        if(aageSolveKrdo){
                            return true;
                        }else{
                            //backtracking
                            grid[row][col]=0;
                        }
                    }
                }
                return false;      //--> 1 - 9 tk saari values try ho chuka h phir bhi solution nhi mila to return false krdo.
            }
        }
    }
    return true;
}

void print(int grid[N][N]){
    for(int i=0 ;i<N;i++){
        for(int j=0; j<N; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
    
    if(solve(grid)==true){
        print(grid);
    }else{
        cout<<"Solution doesn't exists"<<endl;
    }

    return 0;
}