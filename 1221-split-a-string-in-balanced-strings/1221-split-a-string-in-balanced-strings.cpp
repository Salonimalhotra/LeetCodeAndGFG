class Solution {
public:
    int balancedStringSplit(string s) {
        int numL=0;
        int numR=0;
        int i=0;
        int j=0;
        int maxCuts=0;
        while(j<s.size()){
             if(s[j]=='L'){
                   numL++;
               }
               else if(s[j]=='R'){
                   numR++;
               }
            
             if(numL!=numR){
                 j++;
             }
             else{
                 maxCuts++;
                 j++;
                 i=j;
                 
             }
            
        }
        return maxCuts;
    }
};