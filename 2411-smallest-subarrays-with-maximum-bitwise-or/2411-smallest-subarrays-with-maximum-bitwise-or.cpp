class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>finalans;
        vector<int>helper(32,0);
        for(int i=nums.size()-1;i>=0;i--){
           for(int j=0;j<32;j++){
             int mask=1<<j;
             if(nums[i] & mask)helper[j]=i;
           }
            int maxIndex=i;
           for(int j=0;j<32;j++){
              if(helper[j]!=0){
                maxIndex=max(maxIndex,helper[j]);
              }
           }
           finalans.push_back(maxIndex-i+1);
        }
       reverse(finalans.begin(),finalans.end());
      return finalans;
    }
};