//Ceiling in a sorted array

/*
Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x,
and the floor is the greatest element smaller than or equal to x.

For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int k, int n,int &res){
    int s = 0;
    int e = n-1;
    int mid = 0;
    while(s<=e){
        mid = (s+e)/2;
        if(k==arr[mid]) res = arr[mid];
        
        if(k<arr[mid]){
            res = arr[mid];
            e = mid-1;
        }
        else{
            res = arr[mid];
            s = mid+1;
        } 
    }
}

int main(){
    int arr[7] = {1, 2, 8, 10, 10, 12, 19};
    int ceilOf = 55;
    int res=0;
    if(ceilOf > arr[6]){
        cout<<"Does'nt exist"<<endl;
        return 0;
    }
    solve(arr,ceilOf,7,res);
    cout<<res<<endl;
    return 0;
}

