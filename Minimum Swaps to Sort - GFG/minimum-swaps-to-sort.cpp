// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool compare(pair<int,int>x ,pair<int,int>y){
    if(x.first<y.first){
        return true;
    }
    else{
        return false;
    }
}
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>ans;
	    for(int i=0;i<nums.size();i++){
	        pair<int,int>p1;
	        p1.first=nums[i];
	        p1.second=i;
	        ans.push_back(p1);
	    }
	    sort(ans.begin(),ans.end(),compare);
	    int minSwaps=0;
	    int i=0;
	    while(i<ans.size()){
	        if(ans[i].second==i){
	            i++;
	        }
	        else if(ans[i].second!=i){
	            int correct=ans[i].second;
	            swap(ans[i],ans[correct]);
	            minSwaps++;
	        }
	    }
	    return minSwaps;
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