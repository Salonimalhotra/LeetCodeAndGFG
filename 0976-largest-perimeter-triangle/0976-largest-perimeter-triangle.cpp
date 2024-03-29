class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return 0;
        int n=nums.size();
        for(int i=n-1;i>=2;i--){
           if((nums[i-2] + nums[i-1])>nums[i]) return nums[i-2] + nums[i-1] + nums[i];
        }
      
        return 0;
    }
};