class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int num=0;
        int x=0;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            int cnt_one=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j] & mask)!=0){
                    cnt_one++;
                }
            }
            if(cnt_one%2!=0){
                num+= pow(2,x) * 1;
                x++;
                continue;
            }
            else{
                if(cnt_one==0){
                   num+= pow(2,x) * 0;
                    x++;
                    
                }
                else{
                       num+= pow(2,x) * 1;
                       x++;
                }
                
            }
        }
        return num;
    }
};