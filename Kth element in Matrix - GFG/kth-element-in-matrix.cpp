// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends


#include<queue>
int countOfLessThanEqualTo(int mat[MAX][MAX],int r,int c,int i,int mid){
        int low=0;
        int high=c-1;
        while(low<=high){
            int md=(low+(high-low)/2);
            if(mat[i][md]<=mid){
                low=md+1;
            }
            else{
                high=md-1;
            }
        }
        return low;
    }
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
//   priority_queue<int>maxHeap;
//         int count=0;
//         for(int i=0;i<n;i++){
//           for(int j=0;j<n;j++){
//               if(count<k){
//                   maxHeap.push(mat[i][j]);
//                   count++;
//               }
//               else if(count>=k){
//                   if(maxHeap.top()>mat[i][j]){
//                       maxHeap.pop();
//                       maxHeap.push(mat[i][j]);
//                   }
//                   count++;
//               }
//           }
//         }
//         return maxHeap.top();   
         int low=mat[0][0];
        int high=mat[n-1][n-1];
        while(low<=high){
            int mid=(low+(high-low)/2);
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=countOfLessThanEqualTo(mat,n,n,i,mid);
            }
            if(cnt<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
}
