#include<vector>
#include<climits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAns=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
//           if(ans+nums[i]<0){
//               ans=0;
//               continue;
//           }
//             ans+=nums[i];
//           maxAns=max(ans,maxAns);
            ans+=nums[i];
            maxAns=max(maxAns,ans);
            if(ans<0){
                ans=0;
            }
            
            
        }
        return maxAns;
        
    }
};