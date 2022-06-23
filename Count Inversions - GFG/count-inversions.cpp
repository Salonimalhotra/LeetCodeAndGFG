// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
  long long merge(long long arr[], long long low, long long mid, long long high){
       long long count = 0;
       long long n1 = mid-low + 1, n2 = high - mid;
       long long left[n1], right[n2];
       for(long long i=0;i<n1;i++)
           left[i] = arr[low+i];
       for(long long i=0;i<n2;i++)
           right[i] = arr[mid+i+1];
       
       long long i=0,j=0,k=low;
       while(i<n1 && j<n2){
           if(left[i] <= right[j]){
               arr[k++] = left[i++];
           }
           else{
               arr[k++] = right[j++];
               count+=(n1-i);
           }
       }
       for(;i<n1;i++){
           arr[k++] = left[i];
       }
       for(;j<n2;j++){
           arr[k++] = right[j];
       }
       return count;
   }
   
   long long mergeSort(long long arr[], long long low, long long high){
      long long count = 0;
       if(low < high){
           long long mid = low+(high-low)/2;
           count +=mergeSort(arr,low,mid);
           count +=mergeSort(arr,mid+1,high);
           count +=merge(arr,low,mid,high);
       }
       return count;
   }
   
   long long int inversionCount(long long arr[], long long N)
   {
       // Your Code Here
       
       return mergeSort(arr,0,N-1);
   }


};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends