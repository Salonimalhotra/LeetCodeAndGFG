#include<cmath>
class Solution {
public:
    int digits(int num){
        if(num<=9){
          return 1;
        }
        return 1+digits(num/10);
    }
    int reverseNumber(int num){
        long ans=0;
        int x=digits(num)-1;
        while(num!=0){
            int y=num%10;
            ans+=y*pow(10,x);
             x--;
            num=num/10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int reversedNumber=reverseNumber(x);
        if(x==reversedNumber){
            return true;
        }
        else{
            return false;
        }
    }
};