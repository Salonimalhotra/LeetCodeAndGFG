// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void helper(vector<int>& ans,vector<int>& nums,int s,int e){
        if(s>e){
            return;
        }
        else if(s==e){
            ans.push_back(nums[s]);
            return;
        }
        int mid=(s+e)/2;
        ans.push_back(nums[mid]);
        helper(ans,nums,s,mid-1);
        helper(ans,nums,mid+1,e);
        return;
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
        helper(ans,nums,0,nums.size()-1);
        return ans;
        
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends