// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
   	int  minimum_difference(vector<int>nums){
   	    // Code here
   	    //n2 approach :-
        //as for 1 element we have n-1 iterations and then n-2 and then n-3 then 1 therefore time complexity is n2
   	    // int n=nums.size();
   	    // int min_diff=INT_MAX;
   	    // for(int i=0;i<n;i++){
   	    //     for(int j=i+1;j<nums.size();j++){
   	    //       int  diff=abs(nums[j]-nums[i]);
   	    //         min_diff=min(min_diff,diff);
   	    //     }
   	    // }
   	    // return min_diff;
   	    sort(nums.begin(),nums.end());
   	    int min_diff=INT_MAX;
   	    for(int i=0;i<nums.size()-1;i++){
   	        int diff=nums[i+1]-nums[i];
   	        min_diff=min(diff,min_diff);
   	    }
   	    return min_diff;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < nums.size(); i++)cin >> nums[i];
		Solution ob;
		int ans = ob.minimum_difference(nums);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends