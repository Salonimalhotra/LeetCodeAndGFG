class Solution {
public:
    void helper(int &totalxor,int index,vector<int>& nums,int curr){
      if(index==nums.size()){
         totalxor= totalxor + curr;
         return;
      }
      
      helper(totalxor,index+1,nums,curr ^ nums[index]);
      helper(totalxor,index+1,nums,curr);
      return;
    }
    int subsetXORSum(vector<int>& nums) {
        int totalxor=0;
        int curr=0;
        helper(totalxor,0,nums,curr);
        return totalxor;
    }
};