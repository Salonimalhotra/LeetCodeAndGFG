class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<32;i++){
            int m= 1<<i;
            if((c & m)!=0){
                if((a & m)!=0 || (b & m)!=0){
                    continue;
                }
                else{
                    cnt++;
                }
            }
            else{
                if((a & m)!=0){
                    cnt++;
                }
                if((b & m)!=0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};