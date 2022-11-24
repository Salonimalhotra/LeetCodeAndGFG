class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxAns=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==1){
            sum++;
            maxAns=max(maxAns,sum);
          }
          else{
            sum=0;
          }
        }
      return maxAns;
    }
};