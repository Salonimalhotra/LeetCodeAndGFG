class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string smallAns=countAndSay(n-1);
        string finalAns="";
        int cnt=1;
        int i=0;
        while(i<smallAns.size()){           
            if(i==smallAns.size()-1 || smallAns[i]!=smallAns[i+1]){
                finalAns.push_back('0' + cnt);
                finalAns.push_back(smallAns[i]);
                cnt=1;
                i++;
            }            
             else if(smallAns[i]==smallAns[i+1]){
                i++;
                cnt++;
            }
        }
        return finalAns;
    }
};