class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        int fS=((nums.size()+1)*(nums.size()))/2;
        int misNum=fS-totalSum;
        return misNum;
    }
};