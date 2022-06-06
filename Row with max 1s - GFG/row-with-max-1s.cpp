// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int binarySearchFirstOcc(vector<vector<int>>arr,int n,int m,int i){
        int s=0;
        int e=m-1;
        int ans=-1;
    
        while(s<=e){
              int mid=s+(e-s)/2;
              if(arr[i][mid]==1){
                  ans=mid;
                  e=mid-1;
              }
              else if(arr[i][mid]<1){
                  s=mid+1;
              }
              else{
                  e=mid-1;;
              }
        }
        return ans;
    }
    
    int binarySearchLastOcc(vector<vector<int>>arr,int n,int m,int i){
        int s=0;
        int e=m-1;
        int ans=-1;
    
        while(s<=e){
              int mid=s+(e-s)/2;
              if(arr[i][mid]==1){
                  ans=mid;
                  s=mid+1;
              }
              else if(arr[i][mid]<1){
                  s=mid+1;
              }
              else{
                  e=mid-1;;
              }
        }
        return ans;
    }
    
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    //Brute force Approach:-O(n*m):-
	    
	   // int maxRowIndex=-1;
	   // int maxCount=INT_MIN;
	   // for(int i=0;i<n;i++)
	   // {
	   //     int count=0;
	   //     for(int j=0;j<m;j++){
	   //         if(arr[i][j]==1){
	   //             count++;
	   //         }
	   //     }
	   //    if(count>maxCount && count!=0){
	   //        maxCount=count;
	   //        maxRowIndex=i;
	   //    }
	   // }
	    
	   // return maxRowIndex;
	   
	   //efficient Approach:- nlog(m);
	   
	   int maxCount=INT_MIN;
	   int rowIndex=-1;
	   
	   for(int i=0;i<n;i++){
	       int firstOcc=binarySearchFirstOcc(arr,n,m,i);
	       if(firstOcc==-1){
	           continue;
	       }
	       int occ=binarySearchLastOcc(arr,n,m,i)-binarySearchFirstOcc(arr,n,m,i)+1;
	       if(occ>maxCount){
	           maxCount=occ;
	           rowIndex=i;
	       }
	   }
	   
	   return rowIndex;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends