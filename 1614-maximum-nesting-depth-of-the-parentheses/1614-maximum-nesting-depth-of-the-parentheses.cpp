class Solution {
public:
    int maxDepth(string s) {
        int maxDepth=0;
        int open=0;
        int closed=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                open--;
            }
            
            maxDepth=max(maxDepth,open);
        }
        return maxDepth;
    }
};