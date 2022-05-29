#include<vector>
#include<queue>
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int i=0;
        int j=0;
        vector<int>ans;
        while(j<nums.size()){
            pq.push(make_pair(nums[j],j));
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                while(pq.size()!=0 && pq.top().second<i){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;
                j++;
            }
        }
        return ans;        
    }
};