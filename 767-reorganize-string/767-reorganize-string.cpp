class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        string finalans="";
        while(pq.size()!=0){
            if(pq.size()==1){
                if(pq.top().first>=2){
                    return "";
                }
                else{
                    finalans.push_back(pq.top().second);
                    break;
                }
            }
            pair<int,char> option1=pq.top();
            pq.pop();
            pair<int,char> option2=pq.top();
            pq.pop();
            char c1=option1.second;
            char c2=option2.second;
            
            finalans.push_back(c1);
            finalans.push_back(c2);
            
            int new1=option1.first-1;
            int new2=option2.first-1;
            if(new1!=0){
                pq.push({new1,c1});
            }
            if(new2!=0){
               pq.push({new2,c2});
            }
        }
        return finalans;
    }
};