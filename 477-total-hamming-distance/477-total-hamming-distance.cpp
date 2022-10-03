class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
          int mask=1<<i;
          int cnt_zeroes=0;
          int cnt_ones=0;
          for(int j=0;j<nums.size();j++){
            if(mask & nums[j]) cnt_ones++;
            else cnt_zeroes++;
          }
          ans+= cnt_zeroes * cnt_ones;
        }
      return ans;
    }
};