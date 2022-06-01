#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        //Brute fore approach
        // for(int i=0;i<nums.size();i++){
        //    for(int j=i+1;j<nums.size();j++){
        //        if(nums[i]+nums[j]==target){
        //            ans.push_back(i);
        //            ans.push_back(j);
        //            return ans;
        //        }
        //    }
        // }
        // return ans;
        //hashmap approach
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end() && i!=mp[target-nums[i]]){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};