//Sorting the the given array using insertionSort Algorithm
/*
Insert an element from unsorted array to its correct position in the sorted array
EXAMPLE: 12 45 23 51 19 8

We consider one part as sorted and other as unsorted
Let starting index be as sorted part
12 | 45 23 51 19 8

then we iterate and arrange each element to ite=s correct position in sorted array

12 45 | 23 51 19 8
12 23 45 | 51 19 8
12 23 45 51 | 19 8
12 19 23 45 51 | 8
8 12 19 23 45 51 | ===> Sorting Done

Time Complexity ==> O(n^2)
Space Complexity ==> O(1)

What are the Boundary Cases of Insertion Sort algorithm?
Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted. 

What are the Algorithmic Paradigm of Insertion Sort algorithm?
Insertion Sort algorithm follows incremental approach.

Is Insertion Sort an in-place sorting algorithm?
Yes, insertion sort is an in-place sorting algorithm.

Is Insertion Sort a stable algorithm?
Yes, insertion sort is a stable sorting algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {5,3,45,62,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}