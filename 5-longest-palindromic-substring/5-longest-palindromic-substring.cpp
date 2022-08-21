class Solution {
public:
    int extendCenter(string s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
         int start=0;
         int end=0;
        for(int i=0;i<s.size();i++){
            int len1=extendCenter(s,i,i);
            // cout<<len1<<endl;
            int len2=extendCenter(s,i,i+1);
            // cout<<len2<<endl;
            int maxlen=max(len1,len2);
            // cout<<maxlen<<endl;
            if(end-start+1<maxlen){
                cout<<"this one is executed"<<endl;
                 start=i-((maxlen-1)/2);
                 end= i+((maxlen)/2);
                cout<<start<<" "<<end<<endl;
            }
        }
       
        return s.substr(start,end-start+1);
    }
};