// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        //Brute force
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(A[i]+A[j]+A[k]==X){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int x=X-A[i];
                if(A[j]+A[k]<x){
                    j++;
                }
                else if(A[j]+A[k]>x){
                    k--;
                }
                else if(A[j]+A[k]==x){
                    return true;
                }
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends