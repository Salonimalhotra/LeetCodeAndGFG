class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);
      
        for(int i=0;i<nums.size();i++){
           if(i==0 || nums[i-1]<nums[i]){
               continue;
           }
           else{
             prefix[i]=prefix[i-1]+1;
           }
        }
      
       for(int j=nums.size()-1;j>=0;j--){
         if(j==nums.size()-1 || nums[j]>nums[j+1]){
              continue;
         }
         else{
              suffix[j]=suffix[j+1]+1;
         }
       }
   
       vector<int>finalans;
       for(int i=k;i<nums.size()-k;i++){
          if(prefix[i-1]>=k && suffix[i+1]>=k){
            finalans.push_back(i);
          }
       }
      return finalans;
    }
};