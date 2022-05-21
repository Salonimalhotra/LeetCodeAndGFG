// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
   public:
    int partition (vector<int>&arr, int low, int high)
    {
       // Your code here
       int pivot=arr[low];
       int cnt=0;
       for(int i=low+1;i<=high;i++){
           if(arr[i]<=pivot){
               cnt++;
           }
       }
       
       int pivotIndex=low+cnt;
       
       //place pivot at its correct pos;
       swap(arr[low],arr[pivotIndex]);
       int i=low;
       int j=high;
       
       while(i<pivotIndex && j>pivotIndex){
           
           while(arr[i]<=arr[pivotIndex]){
               i++;
           }
           
           while(arr[j]>arr[pivotIndex]){
               j--;
           }
           
          if(i<pivotIndex && j>pivotIndex){
              swap(arr[i],arr[j]);
              i++;
              j--;
          }
       }
       return pivotIndex;
    }
    void quickSort(vector<int>&arr, int low, int high)
    {
        // code here
        if(low>=high){
            return;
        }
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
        return;
    }
    
    // public:
    // int partition (vector<int>&arr, int low, int high)
    // {
    //   // Your code here
    //   int pivot=arr[low];
    //   int cnt=0;
    //   for(int i=low+1;i<=high;i++){
    //       if(arr[i]<=pivot){
    //           cnt++;
    //       }
    //   }
       
    //   int pivotIndex=low+cnt;
       
    //   //place pivot at its correct pos;
    //   swap(arr[low],arr[pivotIndex]);
    //   int i=low;
    //   int j=high;
       
    //   while(i<pivotIndex && j>pivotIndex){
           
    //       while(arr[i]<=arr[pivotIndex]){
    //           i++;
    //       }
           
    //       while(arr[j]>arr[pivotIndex]){
    //           j--;
    //       }
           
    //       if(i<pivotIndex && j>pivotIndex){
    //           swap(arr[i],arr[j]);
    //           i++;
    //           j--;
    //       }
    //   }
    //   return pivotIndex;
    // }
    vector<int> sortArr(vector<int>&arr, int n){
        
    //complete the function here
    int low=0;
    int high=n-1;
    quickSort(arr,low,high);
    return arr;
    }
};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}

  // } Driver Code Ends