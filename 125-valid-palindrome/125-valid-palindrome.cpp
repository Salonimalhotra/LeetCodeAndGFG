#include<string>
class Solution {
public:
    bool helper(string s1){
        int i=0;
        int j=s1.size()-1;
        while(i<=j){
            if(s1[i]!=s1[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        if(s==""){
            return true;
        }
        string s1="";
        // uppercase characters are from 65 to 90
        //lowercase characters are from 97 to 122
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90){
                s1.push_back(s[i]+32);
            }
            else if(s[i]>=97 && s[i]<=122){
                s1.push_back(s[i]);
            }
             else if(s[i]>= '0' && s[i] <= '9'){
                s1.push_back(s[i]);
            }
        } 
        // cout<<s1<<endl;
        return helper(s1);
        
    }
};