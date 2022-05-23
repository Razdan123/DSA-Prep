// Inserting values in a heap
/*
What is heap? --> Heap is nothing but a complete Binary Tree (CBT). It is a special tree based Data-Structure.
                  Heap can be of two types i) Max Heap & ii) Min Heap

What is CBT ? --> A tree where all the levels of it should be complete except possible the last level. And the last level
                  should have the leaves starting from left.(As left as possible)

It has some special properties described below : -
            If the parent is at (i)th index then: 
                 i)  The left child is given by -> 2*i
                 ii) The right child is given by -> 2*i + 1
            If the child is at (i)th index its parent index is given by -> i/2

Heap is basically the collection of data in an array format that starts from (i=1)
        [x][50][30][40][20][25]
        0   1   2   3   4   5

                  50
                /    \ 
              30     40     --> Max Heap Example
            /   \   /  \
           20   25
*/

#include<bits/stdc++.h>
using namespace std;

//Creating a class Heap
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        this->arr[0] = -1;
        this->size = 0;
    }

    //Function to insert data       TIME COMPLEXITY --> O(log n)
    void insertHeap(int data){
        size = size + 1;
        int index = size;
        arr[index] = data;
        
        while(index>1){        
        int parent = index/2;
        if(arr[parent] < arr[index])
        {
            swap(arr[parent],arr[index]);
            index = parent;
        }else{
            return;
        }}
    }

    void print(){
        for(int i=1 ; i <= size; i++){
            cout<<arr[i]<<" ";
        }
    }

};


int main(){
    heap h;
    h.insertHeap(50);
    h.insertHeap(46);
    h.insertHeap(35);
    h.insertHeap(60);
    h.print();
    return 0;
}