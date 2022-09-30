class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int cntZeroes=0;
       
        int i=0;
        int j=0;
      
        while(j<nums.size()){
            if(nums[j]==0){
              cntZeroes++;
            }
             
            if(cntZeroes<=k){
              maxlen=max(maxlen,j-i+1);
                j++;
            }
             
            else if(cntZeroes>k){
              while(cntZeroes>k){
                 if(nums[i]==0){
                   cntZeroes--;
                  
                 }
                 i++;                
              }
             
              j++;
            }
          
        }
      return maxlen;
    }
};