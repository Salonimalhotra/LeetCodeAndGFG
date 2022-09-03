class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0){
                st.push(make_pair(s[i],1));
            }
            else{
                if(st.top().first==s[i]){
                    if(st.top().second+1==k){
                        int cnt=1;
                        while(st.size()!=0 && st.top().first==s[i] && cnt<=k){
                            st.pop();
                            cnt++;
                        }
                    }
                    else{
                        st.push(make_pair(s[i],st.top().second+1));
                    }
                }
                else{
                     st.push(make_pair(s[i],1)); 
                }
            }
            
        }
        
        string final_ans="";
        while(st.size()!=0){
            final_ans.push_back(st.top().first);
            st.pop();
        }
        reverse(final_ans.begin(),final_ans.end());
        return final_ans;
    }
};