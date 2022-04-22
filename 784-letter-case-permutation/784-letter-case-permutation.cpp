class Solution {
public:
    int helper(string s,vector<string>&ans){
        if(s.size()==0){
            string x="";
            ans.push_back(x);
            return 1;
        }
        vector<string>ans1;
        int smallSize=helper(s.substr(1),ans1);
        if(s[0]>='a' && s[0]<='z'){
            for(int i=0;i<smallSize;i++){
            string x="";
            x.push_back(s[0]);
            ans.push_back(x.append(ans1[i]));
            x="";
            x.push_back(s[0]-32);
            ans.push_back(x.append(ans1[i]));
            }
              return smallSize*2;
        }
        
        else if(s[0]>='A' && s[0]<='Z'){
          for(int i=0;i<smallSize;i++){
            string x="";
            x.push_back(s[0]);
            ans.push_back(x.append(ans1[i]));
            x="";
            x.push_back(s[0]+32);
            ans.push_back(x.append(ans1[i]));
            }
              return smallSize*2;
        }
        
        else{
            for(int i=0;i<smallSize;i++){
                string x="";
                   x.push_back(s[0]);
                ans.push_back(x.append(ans1[i]));
            }
            return smallSize;
        }  
       
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans; 
        int size=helper(s,ans);
        return ans;
    }
};