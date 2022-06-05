// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long temp[],long long int s,long long int mid,long long int e,long long int &inv_count){
        long long int i=s;
        long long int j=mid+1;
       long long int k=s;
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else if(arr[i]>arr[j]){
                inv_count+=mid-i+1;
                temp[k++]=arr[j++];
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        while(j<=e){
            temp[k++]=arr[j++];
        }
        
        for(int i=s;i<=e;i++){
            arr[i]=temp[i];
        }
        return ;
    }
    void mergeSort(long long arr[],long long temp[],long long int s,long long int e,long long int &inv_count){
        if(s>=e){
            return ;
        }
        long long int mid=(s+e)/2;
        mergeSort(arr,temp,s,mid,inv_count);
        mergeSort(arr,temp,mid+1,e,inv_count);
        merge(arr,temp,s,mid,e,inv_count);
        return;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        long long int inv_count=0;
        mergeSort(arr,temp,0,N-1,inv_count);
        return inv_count;
        
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