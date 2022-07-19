//Sorting the the given array using QuickSort Algorithm

/*
    Time Complexity :
    Best TC = O(nlog(n))
    Avg TC = O(nlog(n))
    Worst TC = A(n^2)  -> When the give array in already in either ascending order or descending order

    Space Complexity : O(n)
*/

/*
Flow of the algorithm :-

1. We will consider the first element as pivot element
2. We will take that element to its correct position in the element
3. We will arrange the array in such that all the element in the left side of the pivot element is smaller &
                                              the elements which are right side whld be larger than the pivot
4. Now as we got the pivot Index we will call our recursion function quickSort first for the left part i.e. start -> pivotIndex-1
                                                                                    and then will call for right part i.e. pivorIndex+1 -> end     
*/


#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(int arr[], int s, int e){
    
    //Considering the first element as pivot element
    int pivotElement = arr[s];

    //Finding the count of elements which are smaller than the pivot elements
    int count = 0;
    for(int i=s+1 ;i<=e; i++){
        if(arr[i]<pivotElement){
            count++;
        }
    }

    //We found the correct position of the pivot element in the array 
    //And thus we swap the pivot element from s index to its correct index
    int pivotIndex = s + count;
    swap(arr[s],arr[pivotIndex]);

    //Now putting the element smaller to pivot in leftSide and bigger to right Side
    int i=s, j=e;
    while(i!=j){
        //Jb tk i th element chota h pivot element se i ko aage badha do
        while(arr[i]<pivotElement){
            i++;
        }
        //Jb tk j th element bada h pivot element se j ko piche badha do
        while(arr[j]>pivotElement){
            j--;
        }

        if(i!=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){

    //Base condition
    while (s>=e)
    {
        return;
    }
    
    //Finding the pivot element index correct position from the given array
    //We will be considering the first element of the array as pivot element
    int p = findPivotIndex(arr,s,e);

    //Calling the quicksort function to sort the left side of pivot element
    quickSort(arr,s,p-1);

    //Calling the quicksort function to sort the left side of pivot element
    quickSort(arr,p+1,e);
}

int main(){

    int arr[8] = {13,55,1,58,34,12,39,7};
    int n = 8;
    
    quickSort(arr,0,n-1);

    //Printing the sorted array in the element
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;

    return 0;
}