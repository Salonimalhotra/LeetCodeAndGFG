class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int prefixsum=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==1){
            prefixsum++;
          }
          else{
            prefixsum--;
          }
          if(prefixsum==0){
            maxlen=max(maxlen,i+1);
          }
          if(mp.find(prefixsum)!=mp.end()){
            maxlen=max(maxlen,i-mp[prefixsum]);
          }
          else{
           mp[prefixsum]=i;  
          }
          
        }
      return maxlen;
    }
};