#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int k=p.size();
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        // int ans=0;
        unordered_map<char,int>map;
        for(int i=0;i<k;i++){
            map[p[i]]++;
            if(map[p[i]]==1){
                count++;
            }
        }
        while(j<n){
            if(map.count(s[j])>0){
                map[s[j]]--;
                if(map[s[j]]==0){
                    count--;
                }
            }
            
            if(j-i+1<k){
                j++;
            }
            
            else if(j-i+1==k){
                if(count==0){
                    ans.push_back(i);
                }
                if(map.count(s[i])>0){
                    map[s[i]]++;
                    if(map[s[i]]==1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};