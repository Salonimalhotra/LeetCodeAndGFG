class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        if(nums.size()<=1){
            return nums;
        }
        int i=0;
        int j=1;
        
        for(int k=0;k<nums.size();k++){
            if(nums[k]%2==0){
                ans[i]=nums[k];
                i+=2;
            }
            else{
                ans[j]=nums[k];
                j+=2;
            }
        }
        return ans;
    }
};