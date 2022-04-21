class Solution {
public:
    int trailingZeroes(int n) {
        int count1=0;
        for(int i=5;i<=n;i*=5){
            count1+=n/i;
        }
        int count2=0;
        for(int j=2;j<=n;j*=2){
            count2+=n/j;
        }
        return min(count1,count2);
    }
};