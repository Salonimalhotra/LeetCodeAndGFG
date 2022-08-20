class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        for(int i=0;i<paths.size();i++){
            mp[paths[i][0]]=paths[i][1];
        }
        
        string finalAns="";
        string temp=paths[0][0];
        while(mp.find(temp)!=mp.end()){
            temp=mp[temp];
        }
        return temp;
    }
};