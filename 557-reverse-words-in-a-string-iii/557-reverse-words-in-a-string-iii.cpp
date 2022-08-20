#include<string>
class Solution {
public:
    void reverse_helper(string &s,int i,int j){
        while(i<=j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        return ;
    }
    string reverseWords(string s) {
        int i=0;
        int j=0;
        while(i<s.size() && j<s.size()){
           if(s[j]!=' '){
               j++;
           }
           else if(s[j]==' '){
               reverse_helper(s,i,j-1);
               i=j+1;
               j++;
           } 
        }
        reverse_helper(s,i,j-1);
        // reverse_helper(s,0,s.size()-1);
        return s;
    }
};