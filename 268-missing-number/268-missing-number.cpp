#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,bool>map;
        int i=0;
        while(i<nums.size()){
            int correct=nums[i];
            if(correct<nums.size() && nums[i]!=nums[correct]){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
       int ans=-1;
        bool check=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans=i;
                check=false;
                break;
            }
        }
        if(check==true){
            return nums.size();
        }
        return ans;
    }
};