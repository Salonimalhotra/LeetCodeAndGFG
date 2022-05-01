#include<vector>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ans=INT_MIN;
        int max_product=1;
        for(int i=0;i<nums.size();i++){
            max_product*=nums[i];
            max_ans=max(max_product,max_ans);
            if(max_product==0){
                max_product=1;
             }
            }
       
          max_product=1;
        for(int i=nums.size()-1;i>=0;i--){
           max_product*=nums[i];
            max_ans=max(max_product,max_ans);
            if(max_product==0){
                max_product=1;
             }
        }
        return max_ans;
    }
};