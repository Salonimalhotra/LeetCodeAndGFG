#include<vector>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int correct=nums[i]-1;
            if(nums[i]!=nums[correct] && i!=correct){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
              if(nums[i]-1!=i){
                  ans=nums[i];
                  break;
              }
        }
        return ans;
    }
};