#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]>=1){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
            else{
                continue;
            }
        }
        return ans;
    }
};