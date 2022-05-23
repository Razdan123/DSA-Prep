//Sorting the array using Heap : TC = O( nlog(n) )
/*
Algorithm :
    1) swap the a[1] -> a[size] : We are doing this cause we know in maxHeap top element
                                  has the highest value;
    2)We will reduce the size of array : size--    

    3)Now the new root will be taken to its correct position using Heapify algorithm

    Will keep this doing until we reach size>1
*/ 
#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[], int size, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= size && arr[largest]<arr[left]){
        largest = left;
    }
    if(right <= size && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

                                                                            
//HeapSort funtion                                                  
void heapSort(int arr[], int size){
    while(size>1){
        //Step 1
        swap(arr[1],arr[size]);
        
        //Step 2
        size--;

        //Step 3
        heapify(arr,size,1);
    }
}


int main(){
    int arr[9] = {-1,10,20,25,6,12,15,4,16};
    int size = 8;

    //Build the tree using heapify
    for(int i=size/2; i>0; i--){
        heapify(arr,size,i);
    }

    for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //heapSort
    heapSort(arr,size);

    for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}