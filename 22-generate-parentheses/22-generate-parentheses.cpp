class Solution {
public:
    void helper(vector<string>&ans,string s1,int cntopen,int cntclosed,int n){
       if(cntopen>n){
         return;
       }
      
       if(cntclosed>cntopen){
         return;
       }
      
       if(cntopen==cntclosed && cntopen==n){
         ans.push_back(s1);
         return;
       }
      
       helper(ans,s1 + '(' ,cntopen+1,cntclosed,n);
       helper(ans,s1 + ')', cntopen,cntclosed+1,n);
       return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(ans,"",0,0,n);
       return ans;
        
    }
};