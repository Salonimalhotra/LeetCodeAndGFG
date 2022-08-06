#include<algorithm>
#include<bits/stdc++.h>
class Solution {
public:
    bool static compare(vector<int>&a1,vector<int>&a2){
        if(a1[0]<a2[0]){
            return true;
        }
        else if(a1[0]==a2[0]){
             if(a1[1]>a2[1]){
                 return true;
             }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);
         vector<int>ans;
        ans.push_back(envelopes[0][1]);
        int len=1;
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>ans.back()){
                ans.push_back(envelopes[i][1]);
                len++;
            }
            else{
                // int idx=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                int left=0;
                int right=ans.size()-1;
                int idx=ans.size()-1;
                while(left<right){
                    int mid=(left) + (right-left)/2;
                    if(ans[mid]>=envelopes[i][1]){
                        right=mid;
                        idx=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }
                ans[idx]=envelopes[i][1];
            }
        }
        return len;   
        
    }
};