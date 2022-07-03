#include<vector>
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>finalAns(nums.size(),-1);
        finalAns[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            finalAns[i]=finalAns[i-1]+nums[i];
        }
        return finalAns;
    }
};