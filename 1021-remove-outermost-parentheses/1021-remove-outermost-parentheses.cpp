class Solution {
public:
    string removeOuterParentheses(string s) {
        queue<char>q;
        int i=0;
        string finalAns="";
        int open=0;
        int close=0;
        while(i<s.size()){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            
            if(open>close){
                q.push(s[i]);
                i++;
            }
            else if(close==open){
                q.pop();
                while(q.size()!=0){
                    finalAns.push_back(q.front());
                    q.pop();
                }
                close=0;
                open=0;
                i++;
            }
        }
        return finalAns;
    }
};