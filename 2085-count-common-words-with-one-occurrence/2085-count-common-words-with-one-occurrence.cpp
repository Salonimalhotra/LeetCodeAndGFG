#include<unordered_map>
#include<string>
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp;
        unordered_map<string,int>mp1;
        for(int i=0;i<words1.size();i++){
            mp[words1[i]]++;
        }
        
        for(int j=0;j<words2.size();j++){
               mp1[words2[j]]++;
        }
        
        int cnt=0;
        for(auto i:mp){
            if(mp1.find(i.first)!=mp1.end() && mp1[i.first]==1 && i.second==1){
                cnt++;
            }
        }
        return cnt;
    }
};