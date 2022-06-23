// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:  
      bool binarySearch(int C[],int start,int end,int x){
         int i=start;
         int j=end;
         while(i<=j){
             int mid=(i+j)/2;
             if(C[mid]==x){
                 return true;
             }
             else if(C[mid]>x){
                 j=mid-1;
             }
             else{
                 i=mid+1;
             }
         }
         return false;
      }
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int>ans1;
            int i=0;
            int j=0;
            int k=0;
            int prev_Element=INT_MIN;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]<B[j]){
                    i++;
                }
                else if(B[j]<C[k]){
                    j++;
                }
                else if(A[i]==B[j] && B[j]==C[k] && A[i]!=prev_Element){
                    ans1.push_back(A[i]);
                    prev_Element=A[i];
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]==B[j] && B[j]==C[k] && A[i]==prev_Element){
                    i++;
                    j++;
                    k++;
                }
                
                else{
                    k++;
                }
            }
            return ans1;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends