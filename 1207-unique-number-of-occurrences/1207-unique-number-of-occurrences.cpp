class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto i:mp){
            if(mp1.find(i.second)==mp.end()){
                mp1[i.second]++;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};