// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        for(int i=0;i<n;i++){
            
            int childIndex=i;
            while(childIndex>0){
                int parentIndex=(childIndex-1)/2;
                if(arr[parentIndex]<arr[childIndex]){
                    int temp=arr[parentIndex];
                    arr[parentIndex]=arr[childIndex];
                    arr[childIndex]=temp;
                    
                    childIndex=parentIndex;
                }
                else{
                    break;
                }
            }
        }
        
        for(int i=n-1;i>0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            
            int parentIndex=0;
            int LCI=2*parentIndex+1;
            int RCI=2*parentIndex+2;
            
            while(LCI<i){
                int max_index=parentIndex;
                if(arr[max_index]<arr[LCI]){
                    max_index=LCI;
                }
                if(RCI<i && arr[max_index]<arr[RCI]){
                    max_index=RCI;
                }
                if(max_index==parentIndex){
                    break;
                }
                
                int temp=arr[parentIndex];
                arr[parentIndex]=arr[max_index];
                arr[max_index]=temp;
                
                parentIndex=max_index;
                LCI=2*parentIndex+1;
                RCI=2*parentIndex+2;
            }
        }
    }
    
    
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends