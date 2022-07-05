#include<string>
class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch>=65 && ch<=90){
                ch+=32;
                s[i]=ch;
            }
        }
        return s;
    }
};