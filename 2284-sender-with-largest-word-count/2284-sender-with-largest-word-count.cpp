#include<unordered_map>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
#include<algorithm>
class Solution {
public:
    int storeCount(vector<string>&messages,int i){
       int countWords=1;
        for(int j=0;j<messages[i].size();j++){
            if(messages[i][j]==' '){
                countWords++;
            }
            else{
                continue;
            }
        }
        return countWords;
        
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>mp;
        for(int i=0;i<senders.size();i++){
            string x=senders[i];
            int count=storeCount(messages,i);
            mp[x]=mp[x]+count;            
        }
        
        // for(auto i:mp){
        //     cout<<i.first<<":"<<i.second<<endl;
        // }
        
        int max_count=INT_MIN;
        for(auto i:mp){
            if(i.second>max_count){
                max_count=i.second;
            }
        }
        string ans="";
        for(auto i:mp){
            if(i.second==max_count){
                if(ans==""){
                    ans=i.first;
                }
                else if(ans<i.first){
                    ans=i.first;                    
                }
                
            }
        }
        return ans;
        
    }
};