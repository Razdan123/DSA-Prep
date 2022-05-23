//Heapify the given the array to (For Ex: Max Heap). --> Max Heapify
/*
For this we need to know a basic point : 
                    For every heap, its leaf nodes will always start from (size/2 + 1)th node,

                            [x][50][30][40][20][25]
                            0   1   2   3   4   5
                    
                  50
                /    \ 
              30     40     --> Max Heap Example:  leaf node will start from = ((5/2)+1) = 3
            /   \               So we can say from (3 to 5) --> leaf nodes will only exist.
           20   25              Leaf nodes are already heapyfied beacuse they are heap themselves (only one element)
                            Therefore, we only need to check and do heapification process from
                            elements between (1 to size/2) as from (size/2 + 1 to size is already a heap individually).

So, for a given array:

Run a loop  for(int i=size/2; i>0; i--){

            heapify(arr,size,i);     ---> THIS FUNCTION WILL DO THE MAIN PROCESS OF HEAPIFICATION by                     
                                          by comparing with other elements. 
            }                            


                Time Complexity --> O(log n)

*/ 

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i){
    int largest = i;
    int left  = 2*i;
    int right = 2*i + 1;

    if(arr[largest]<arr[left] && left<=size){
        largest = left;
    }
    if(arr[largest]<arr[right] && right<=size){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}



int main(){
    int arr[9] = {-1,10,20,25,6,12,15,4,16};
    int size = 8;

    //Building the heap(Heap Creation) --> Time complexity for Building a Binary Heap is O(n).
    for(int i=size/2; i>0; i--){
        heapify(arr,size,i);
    }
    
    for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}