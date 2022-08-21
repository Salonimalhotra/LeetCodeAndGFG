#include<string>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mp){
           pq.push(make_pair(i.second,i.first));
        }
        string finalAns="";
        while(pq.size()!=0){
            pair<int,char>top=pq.top();
            pq.pop();
            int x=top.first;
            char y=top.second;
            while(x!=0){
                finalAns.push_back(y);
                x--;
            }
            
        }
        return finalAns;
    }
};