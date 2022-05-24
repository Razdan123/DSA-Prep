//PRIORITY QUEUE --> A STL Data Structure
/*
From Priority queue we can make :
                                MAXheap --> BY Default Priority_Queue make MAXheap
                                MINheap
We need to import <Queue> header file. 
*/

#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(50);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(10);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
        //pq.pop();
        //pq.pop();
    if(pq.empty()){
        cout<<"The queue is empty."<<endl;
    }else cout<<"The queue is not empty."<<endl;

    cout<<"The queue size is: "<<pq.size()<<endl;



    //For Min HEAP :-->
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(50);
    minHeap.push(20);
    minHeap.push(30);
    minHeap.push(40);
    minHeap.push(10);

    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<endl;
        minHeap.pop();
    // cout<<minHeap.top()<<endl;
    //     minHeap.pop();
    // cout<<minHeap.top()<<endl;
    //     minHeap.pop();
    // cout<<minHeap.top()<<endl;
    return 0;
}
