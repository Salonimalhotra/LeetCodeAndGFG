// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<vector>
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>nums1;
	    for(int i=0;i<nums.size();i++){
	        pair<int,int>p;
	        p.first=nums[i];
	        p.second=i;
	        nums1.push_back(p);
	    }
	    
	    sort(nums1.begin(),nums1.end());
	    
	    int c=0;
	    int i=0;
	    while(i<nums1.size()){
	        if(nums1[i].second==i){
	            i++;
	        }
	        else{
	            c++;
	            swap(nums1[i],nums1[nums1[i].second]);
	            
	        }
	    }
	  return c;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends