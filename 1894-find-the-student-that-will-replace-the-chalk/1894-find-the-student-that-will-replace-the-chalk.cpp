class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        vector<long long>prefixSum(chalk.size(),0);
        for(int i=0;i<chalk.size();i++){
          sum+=chalk[i];
          prefixSum[i]=sum;
        }
      
        k=k%sum;
        // for(int i=0;i<chalk.size();i++){
        //   if(chalk[i]<=k){
        //     k-=chalk[i];
        //   }
        //   else{
        //     return i;
        //   }
        // }    
      int ans=upper_bound(prefixSum.begin(),prefixSum.end(),k)-prefixSum.begin();
      return ans;
       
    }
};