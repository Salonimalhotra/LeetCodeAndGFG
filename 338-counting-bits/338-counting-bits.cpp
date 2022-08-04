#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int countingBits(int x){
        int cnt=0;
        while(x){
            x=x & (x-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>finalAns(n+1,0);
        finalAns[0]=0;
        for(int i=1;i<=n;i++){
            finalAns[i]=countingBits(i);
        }
        return finalAns;
    }
};