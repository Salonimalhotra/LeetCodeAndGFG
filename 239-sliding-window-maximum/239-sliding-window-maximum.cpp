#include<vector>
#include<queue>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>maxHeap;
        for(int i=0;i<nums.size();i++){
            if(i<k-1){
                maxHeap.push(make_pair(nums[i],i));
                continue;
            }
            maxHeap.push(make_pair(nums[i],i));
            while(maxHeap.size()!=0 && maxHeap.top().second<=i-k){
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};