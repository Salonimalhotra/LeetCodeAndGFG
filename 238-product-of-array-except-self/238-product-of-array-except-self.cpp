#include<vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size(),0);
        prefix[0]=1;
        int prod=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prod;
            prod=prod*nums[i];
        }
        
          vector<int>suffix(nums.size(),0);
          suffix[nums.size()-1]=1;
          prod=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=prod;
            prod=prod*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=prefix[i]*suffix[i];
        }
        return nums;
    }
};