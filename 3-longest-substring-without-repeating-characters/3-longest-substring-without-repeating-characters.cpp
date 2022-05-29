#include<string>
#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        
         if(s.length()==0){
           return 0;
       } 
        
        int i=0;
        int j=0;
        int n=s.size();
        int maxlen=0;
        while(j<n){
            map[s[j]]++;
            
            if(map.size()==j-i+1){
                maxlen=max(maxlen,j-i+1);
                j++;
            }
            
            else if(map.size()<j-i+1){
                while(map.size()<j-i+1){
                    map[s[i]]--;
                    if(map[s[i]]==0){
                        map.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxlen;
    }
};