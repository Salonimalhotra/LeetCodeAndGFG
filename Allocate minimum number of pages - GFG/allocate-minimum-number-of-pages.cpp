// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++
bool isPossible(int A[],int N,int M,int x){
    int sum=0;
    int numberStudents=1;
    for(int i=0;i<N;i++){
        if(sum+A[i]<=x){
            sum+=A[i];
            
        }
        else{
            numberStudents++;
            if(numberStudents>M || A[i]>x){
                return false;
            }
            sum=A[i];
            
        }
    }
    return true;
}
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int maxPages=INT_MIN;
        for(int i=0;i<N;i++){
            if(A[i]>maxPages){
                maxPages=A[i];
            }
        }
        int totalPages=0;
        for(int i=0;i<N;i++){
            totalPages+=A[i];
        }
        int start=maxPages;
        int end=totalPages;
        int ans=-1;
        while(start<=end){
            int mid=(start+(end-start)/2);
            if(isPossible(A,N,M,mid)==true){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends