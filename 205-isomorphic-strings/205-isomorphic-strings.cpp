class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end() && mp1.find(t[i])==mp1.end()){
                mp[s[i]]=t[i];
                mp1[t[i]]=s[i];
            }
            else if(mp[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};