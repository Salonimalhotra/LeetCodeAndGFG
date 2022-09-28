class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_p=start ^ goal;
        int cnt=0;
        while(xor_p!=0){
            if((xor_p & 1)==1){
                cnt++;
            }
            xor_p=xor_p>>1;
        }
        return cnt;
    }
};