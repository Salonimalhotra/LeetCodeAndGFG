class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int cnt=0;
        int j=0;
        int maxlen=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt++;
                
            }
           
            
            if(cnt<=1){
                maxlen=max(maxlen,j-i+1);
                j++;
            }
            
            else if(cnt>1){
                while(cnt>1 && i<nums.size()){
                    if(nums[i]==0){
                        cnt--;
                        i++;
                    }
                    else{
                        i++;
                    }
                }
                j++;                
            }
        }
        return maxlen;
    }
};