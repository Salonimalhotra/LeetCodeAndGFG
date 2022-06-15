#include<vector>
#include<string>
class Solution {
public:
    string getOptions(char x){
        int lastD=x-'0';
        string options[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        return options[lastD];
    }
    void helper(string digits,string output,vector<string>&ans){
        if(digits.size()==0){
            if(output.size()==0){
                return;
            }
            ans.push_back(output);
            return;
        }
        string ld=getOptions(digits[0]);
        for(int i=0;i<ld.size();i++){
            helper(digits.substr(1),output+ld[i],ans);
        }
        return;        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        helper(digits,output,ans);
        return ans;
    }
};