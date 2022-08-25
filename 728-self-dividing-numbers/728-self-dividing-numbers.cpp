#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    bool selfDivisible(int num){
        int x=num;
        while(x!=0){
            int ld=x%10;
            if(ld!=0 && num%ld==0){
                x=x/10;
            }
            else{
                return false;
            }
            
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
       vector<int>ans;
       for(int i=left;i<=right;i++){
           int x=i;
           if(selfDivisible(i)==true){
               ans.push_back(i);
           }
       } 
      return ans;  
    }
};