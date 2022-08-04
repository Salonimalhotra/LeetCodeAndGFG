#include<vector>
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=0){
            return 0;
        }
        else if(nums.size()==1){
            return nums[0];
        }
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<nums.size();i++){
            int incl=prev2 + nums[i];
            int excl=prev1;
            int ans=max(incl,excl);
            
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
};