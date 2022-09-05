class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0){
                st.push(s[i]);
            }
            else if(st.size()!=0){
                if(st.top() + 32==s[i] || st.top()-32==s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
                
            
        }
        s.clear();
        while(st.size()!=0){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};