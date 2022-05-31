//Finding the Kth smallest element in the given array using Heap
/*
There can be two approach for this problem:-
    1)Sort the array using HeapSort and find the arr[k-1]th element.

    2)Algo for this is described  below:-
        i) Make a MAXheap of first K elements from the given array; (0 -->se le kar--> K-1 tk)
        ii)Now there will be elements from (K -->se le kr--> n-1 tk)
        iii)Compare the remaining element with the heap.top().
                    if(element < heap.top()){
                        heap.pop();
                        heap.push(element); --> Then again arrage in heap format.
                    }
        iv) Do the above till last element and then the TOP element of the heap will give us the Kth smallest element
*/

//WE CAN USE PRIORITY_QUEUE FOR Performing the Heap Operations

/*
Yaha pe to Kth smallest bola tha  to MAX Heap lga ke nikaal liya.
LEKIN
Agar Kth LARGEST bolega to MINHeap lga ke nikal lenge
*/

//SpaceComplexity --> O(K)   && TimeComplexity --> ?

//GFG Implementation

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        for(int i=k; i<=r; i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        int ans = pq.top();
        return ans;
    }
};