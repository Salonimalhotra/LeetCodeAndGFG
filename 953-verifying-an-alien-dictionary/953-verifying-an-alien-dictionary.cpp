#include<bits/stdc++.h>
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size()==0 || words.size()==1){
            return true;
        }
        unordered_map<char,int>orderNum;
        int k=26;
        for(int i=0;i<order.size();i++){
            orderNum[order[i]]=k;
            k--;
        }
        int i=1;
       while(i<words.size()){
            int j=i-1;
            int x1=0;
            int x2=0;
           while(x1<words[j].size() && x2<words[i].size()){
               // cout<<words[j][x1]<<" "<<words[i][x2]<<endl;
               // cout<<orderNum[words[j][x1]]<<" "<<orderNum[words[i][x2]]<<endl;
               if(orderNum[words[j][x1]]<orderNum[words[i][x2]]){
                   return false;
               }
               else if(orderNum[words[j][x1]]>orderNum[words[i][x2]]){
                    break;
               }
               else if(orderNum[words[j][x1]]==orderNum[words[i][x2]]){
                   x1++;
                   x2++;
               }
           }
            if(x1<words[j].size() && x2==words[i].size()){
                return false;
            }
            else{
                i++;
            }
           
        }      
     
        return true;
     
    }
};