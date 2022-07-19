//Sorting the given array using bubbleSort

/*
We just see 2 adjacent elements in the array ans if the prev element is less than the after element tha
we swap both of the elements.

In every one complete iteration the largets element will go at the last and thus we will exclude that
from the next iteration

Time Complexity : 
                Worst and the Average Case ==> O(n^2)  The worst case occurs when an array is reverse sorted.
                Best Case ==> O(n)                     The best case occurs when an array is already sorted.

Bubble Sort is stable by default
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[5] = {45,13,35,6,18};
    int n = 5;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);

        }
    }

    //Printing 
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}