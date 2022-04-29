// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int *output=new int[n];
       output[0]=a[0];
       for(int i=1;i<n;i++){
           output[i]=a[i];
           for(int j=i-1;j>=0;j--){
               if(a[j]<a[i]){
                   if(output[j]+a[i]>output[i]){
                       output[i]=a[i]+output[j];
                   }
               }
               
           }
       }
       
       int best_ans=INT_MIN;
       for(int i=0;i<n;i++){
           best_ans=max(best_ans,output[i]);
       }
       return best_ans;
       
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends