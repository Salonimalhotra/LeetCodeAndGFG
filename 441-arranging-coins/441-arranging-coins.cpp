class Solution {
public:
    int arrangeCoins(int n) {
        if(n<1){
            return 0;
        }
        int i=1;
        int row=0;
        while(n-i>=0){
            n=n-i;
            i++;
            row++;
        }
        return row;
    }
};