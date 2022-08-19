#include<unordered_map>
class Solution {
public:
  string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        string res;
        int cnt=1;
        for(int i=0;i<s.length();i++){
            if(i==s.size()-1||s[i]!=s[i+1]){
                res+=to_string(cnt);
                res+=s[i];
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        return res;
    }
};