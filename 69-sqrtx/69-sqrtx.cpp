class Solution {
public:
    long long int  mySqrt(int x) {
        if(x==0){
            return 0;
        }
        else if(x==1){
            return 1;
        }
        int s=1;
        int e=x/2;
        long long ans=-1;
        while(s<=e){
           long long int  mid=(s+(e-s)/2);
            long long int y=mid*mid;
            if(y==x){
                return mid;
            }
            else if(y<x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};