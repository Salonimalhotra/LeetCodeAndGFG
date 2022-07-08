#include<vector>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps=1;
        int steps=nums[0];
        int maxreach=nums[0];
                
        if(nums.size()<=1){
            return true;
        }
        
        if(nums[0]==0){
            return false;
        }
        
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1){
                return true;
            }
            steps--;
            maxreach=max(maxreach,nums[i]+i);
            if(steps==0){
                jumps++;
                if(i>=maxreach){
                    return false;
                }
                steps=maxreach-i;
            }
        }
        
        return  false;
    }
};