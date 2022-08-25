class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=-1;
        if(needle.size()==0){
            return 0;
        }
        else if(needle.size()>haystack.size()){
            return -1;
        }
        for(int i=0;i<haystack.size();){
           if(haystack[i]==needle[0]){
               int j=0;
               int startIndex=i;
               while(startIndex<haystack.size() && j<needle.size() && haystack[startIndex]==needle[j]){
                   startIndex++;
                   j++;
               }
               if(j==needle.size()){
                   return i;
               }
               else{
                   i++;
               }
           }
            else{
                i++;
            }
        }
        return -1;
    }
};