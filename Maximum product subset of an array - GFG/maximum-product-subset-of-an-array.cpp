// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        // sort(a.begin(),a.end());
        int min_z=0;
        int min_pos=0;
        int min_neg=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==0){
                min_z++;
            }
            else if(a[i]<0){
                min_neg++;
            }
            else if(a[i]>0){
                min_pos++;
            }
        }
        
        int mod=pow(10,9)+7;
        if(min_neg%2==0 || min_neg==0){
            long long int product=1;
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    continue;
                }
                product*=a[i];
                product=product%mod;
            }
            return product;
        }
        
        else if(min_neg%2!=0 && (min_neg>1 || min_pos!=0)){
           int minIndex=-1;
           for(int i=0;i<n;i++){
               if(a[i]<0){
                   if(minIndex==-1){
                       minIndex=i;
                       
                   }
                   else{
                       if(abs(a[minIndex])>abs(a[i])){
                           minIndex=i;
                       }
                   }
               }
           }
           
           long long int product=1;
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    continue;
                }
                if(i==minIndex){
                    continue;
                }
                product*=a[i];
                product=product%mod;
            }
            return product;
           
        }
        else if(min_neg==1 && min_pos==0){
             if(min_z>0 && min_pos==0){
                 return 0;
             }
             else if(min_z==0 && min_pos==0){
                 return a[0];
             }
        }
        
        
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends