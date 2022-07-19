//Problem: Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
/*
The time complexity of the binary search algorithm is O(log n). 
The best-case time complexity would be O(1) when the central index would directly match the desired value.

The space complexity of the binary search algorithm depends on the implementation of the algorithm. 
There are two ways of implementing it:
        Iterative method SC -> O(1)
        Recursive method SC -> O(log n)
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch_rec(int arr[], int key, int start, int end){
    
    while (start<=end)
    {
        int mid = (start+end)/2;

        if(key==arr[mid]) return mid;

        if(key<arr[mid]) return binarySearch_rec(arr,key,start,mid-1);
        
        return binarySearch_rec(arr,key,mid+1,end);
    }
    return -1;

}


int binarySearch_itr(int arr[], int key, int start, int end){
    while(start<=end){
        int mid = (start+end)/2;
        if(key==arr[mid]){
            return mid;
        }

        else if(key>arr[mid]){
            start = mid+1;
        }

        else if(key<arr[mid]){
            end = mid-1;
        }
    }

    return -1;
    
}

int  main(){
    int arr[6]={1,2,4,5,9,12};
    int key;
    cout<<"Enter the key that you wanna search: ";
    cin>>key;
    int ans = binarySearch_rec(arr,key,0,5);
    cout<<ans<<endl;
    return 0;
}