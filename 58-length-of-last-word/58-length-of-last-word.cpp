class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        for(int i=0;i<s.size();){
            if(s[i]==' '){
                i++;
            }
            else{
                string s1="";
                while(s[i]!=' ' && i<s.size()){
                    s1.push_back(s[i]);
                    // cout<<s[i]<<endl;
                    i++;
                }
                len=s1.size();
                // cout<<len<<endl;
            }
        }
        return len;
    }
};