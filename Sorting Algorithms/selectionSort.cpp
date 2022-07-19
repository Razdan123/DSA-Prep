// Sort the given array using selection Sort
 /*
Approach:
We start from i=0 index and look for the element in the array which is smallest except i=0 th element.
After we get the smallest element i.e. from j=i+1 --> j=n-1 We will swap it from with the selected i.

Will keep doing it untill we sort the enntire array

Time Complexity : O(n^2)
It doesn't have any best case

Space Complexity = O(1)

This is In-place sorting algorithm
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6] = {25,23,3,6,15,13};
    int n = 6;

    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
                
        }
        swap(arr[i],arr[minIndex]);
    }

    for(int i=0 ;i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}