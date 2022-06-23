#include<bits/stdc++.h>
class Solution {
public:    
    string reverseVowels(string s) {
        if(s.size()==0){
            return s;
        }
        int i=0;
        int j=s.size()-1;
        while(i<j && i<s.size() && j>=0){
            while(i<s.size() && s[i]!='a' && s[i]!='e' &&  s[i]!='i' &&  s[i]!='o' &&  s[i]!='u' && s[i]!='A' && s[i]!='E' &&  s[i]!='I' &&  s[i]!='O' &&  s[i]!='U'){
                i++;
            }
            while(j>=0 && s[j]!='a' && s[j]!='e' &&  s[j]!='i' &&  s[j]!='o' &&  s[j]!='u'  && s[j]!='A' && s[j]!='E' &&  s[j]!='I' &&  s[j]!='O' &&  s[j]!='U'){
                j--;
            }
            if(i<j){
            // cout<<s[i]<<" "<<s[j]<<endl;
            swap(s[i],s[j]);
            i++;
            j--;
            }
        }
        return s;
    }
};