// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    int nextGap(int gap)
   {
    if (gap <= 1)
        return 0;
         
    return (int)ceil(gap / 2.0);
  }
   void swap(int nums[], int i, int j)
   {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
   }

    void merge(int arr[], int start, int m, int end)
    {
         // Your code here
         int gap = end - start + 1;
     
      for(gap = nextGap(gap);
        gap > 0; gap = nextGap(gap))
      {
        for(int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (arr[i] > arr[j])
                swap(arr, i, j);
            }
       }
    }
  
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        return;
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends