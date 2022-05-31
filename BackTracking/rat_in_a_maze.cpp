// RAT IN A MAZE --> Followed from Apna College DSA Video Link : youtube.com/watch?v=4BBB0mvvbGA

#include<bits/stdc++.h>
using namespace std;

/*
Input Format : 2D array
{1, 0, 1, 0, 1}
{1, 1, 1, 1, 0}
{0, 1, 0, 1, 0}    Here 
{1, 0, 0, 1, 1}         1 -> Blocks that are free from obstacles and can be visited by the RAT
{1, 1, 1, 0, 1}         0 -> Blocks with Obstacles, Rat can'nt go

Expected Output Format : 2D array
{1, 0, 0, 0, 0}
{1, 1, 1, 1, 0}
{0, 0, 0, 1, 0}     Here 1 -> the path followed by the Rat to reach (n-1 , n-1)
{0, 0, 0, 1, 1}
{0, 0, 0, 0, 1}
*/


//Declaring the funtion to check wheather the path exists or not
bool isSafe(int** arr, int x, int y, int n){        //int** arr  --> using this we are allocating a dynamic memory to the array.

    //Checking the boundary conditions and the validation of the block
    //if [x][y] =1 then we can visit otherwise it is an obstacle and can'nt be visisted
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }

    //otherwise it is an obstacle and can'nt be visisted
    return false;
}

bool rat_in_maze(int** arr, int x, int y, int n, int** solArr){             //int** solArr -> will store our output and again dynamic allocation of memory
    
    //BASE CASE
    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return true;
    }



    if(isSafe(arr,x,y,n)){  //Checking the conditon of above declared funtion --> if true then only execute
        solArr[x][y]=1;     //If true place assume that the path we chose is correct and mark in the solArr as 1.(It may be wrong but will rectify it in future)
        if(rat_in_maze(arr,x+1,y,n,solArr)){ //Calling the funtion recursively -> send the RAT to the Right of the block
            return true;
        }
        if(rat_in_maze(arr,x,y+1,n,solArr)){ //Calling the funtion recursively -> send the RAT to the Left of the block
            return true;
        }

        //If both of the above condition isn'nt satisfied we will we will get to know that the route we chose is wrong
        //and so we will backtrack (rectifying out previous assumption)
        solArr[x][y]=0;  // --> BACKTRACKING

        return false;
    }

    //if the block doesn't satisfies the isSafe funtion Simply return false.
    return false;
}  

int main(){
    int n;
    cin>>n;

    //Declaring an array for the input
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i]= new int[n];
    }   

    //Taking input from the user
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    //Declaring a 2D array for the solution and initialising every element with 0.
    int** solArr = new int*[n];
    for(int i=0; i<n; i++){
        solArr[i]= new int[n];
        for(int j=0; j<n; j++){
            solArr[i][j]=0;
        }
    }

    cout<<"solution below"<<endl;

    // If the rat is successfully reaching to the (n-1,n-1) position. Then print the path
    if(rat_in_maze(arr,0,0,n,solArr)){  

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<solArr[i][j]<<" ";
            }cout<<endl;
        }
    }

    return 0;
}


// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1