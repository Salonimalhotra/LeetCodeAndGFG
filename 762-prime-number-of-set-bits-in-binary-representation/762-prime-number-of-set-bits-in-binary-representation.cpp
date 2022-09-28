class Solution {
public:
    bool isPrime(int num){
        if(num==1) return false;
        for(int i=2;i<num;i++){
               if((num%i)==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int j=left;j<=right;j++){
           int cnt1=0;
            for(int i=0;i<32;i++){
                 int m=1<<i;
                if((j & m)!=0) cnt1++;
            }
            if(isPrime(cnt1)==true) {
                // cout<<j<<" "<<cnt1<<endl;
                cnt++;
                }
        }
        return cnt;        
    }
};