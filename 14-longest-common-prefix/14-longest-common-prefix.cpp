class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return ""; 
          }
        string ans=strs[0];
        string ans1="";
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<min(strs[i].size(),ans.size());j++){
                 if(strs[i][j]==ans[j]){
                     ans1.push_back(strs[i][j]);                     
                 }
                else{
                    break;
                }                
            }
            ans=ans1;
            ans1="";
        }
        return ans;
    }
};