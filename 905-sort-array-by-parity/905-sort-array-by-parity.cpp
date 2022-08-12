#include<bits/stdc++.h>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low=0;
        int high=0;
        while(high<nums.size()){
            if(nums[high]%2==0){
                swap(nums[low],nums[high]);
                low++;
                high++;
            }
            else{
                high++;
            }
        }
        return nums;
    }
};