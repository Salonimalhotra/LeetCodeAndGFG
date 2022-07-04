#include<bits/stdc++.h>
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newString="";
        int i=0;
        int j=0;
        while(i<s.size()){
             if(i==spaces[j]){
                 newString+=' ';
                 j++;
             }
            else{
                newString+=s[i];
                i++;
            }
            if(j==spaces.size()){
                break;
            }
            
        }
        
        while(i<s.size()){
            newString+=s[i++];
        }
        
        return newString;
    }
};