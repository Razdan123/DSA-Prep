// Deleting a node/index from a heap TIME COMPLEXITY --> O(log n)
/*
    Steps to < DELETE a ROOT node > from heap -->
    1) The node which is present in the last of the heap : replace its value from the last to the root node i.e. arr[size]=arr[1];
    2) Delete the last node (Free the Space)
    3) Start from root and keep check to its corresponding childrens the values and keep swapping untill you reach to the correct position.
*/

#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size = 0;
    }

    void insert(int data){   //T.C. --> O(log n)

        size = size + 1;
        int index = size;
        arr[index] = data;

        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }

    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteRoot(){  //T.C. --> O(log n)
        if(size<1){
            cout<<"Heap is empty : Nothing  to delete"<<endl;
        }

        //Step 1 -->
        arr[1]=arr[size];

        //Step 2 -->
        size--;

         //Step 3 -->
        //Taking root to correct position
        for(int i=1; i<=size; i++){   //This may be wrong for some case.. I wrote it myself but whatever I checked Its working fine.

               if(arr[i]<arr[i+1]){
                swap(arr[i],arr[i+1]);
                i=i+1;
                }
                else if(arr[i]<arr[i+2]){
                swap(arr[i],arr[i+2]);
                i=i+1;
                }
                else{
                    return;
                }
        }
    }

};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteRoot();
    h.print();
    return 0;
}