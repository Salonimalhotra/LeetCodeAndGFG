#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    void reverseh(vector<int>&ans,int l,int e){
        int i=l;
        int j=e;
        while(i<=j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
        return;
    }
    bool nextPermutation(vector<int>&ans){
        int index=-1;
        bool flag=false;
        for(int i=ans.size()-1;i>0;i--){
            if(ans[i]>ans[i-1]){
                index=i-1;
                flag=true;
                break;
            }
        }
        if(flag==false){
            return false;
        }
        int index2=-1;
        for(int i=ans.size()-1;i>index;i--){
            if(ans[i]>ans[index]){
                index2=i;
                break;
            }
        }
        swap(ans[index],ans[index2]);
        reverseh(ans,index+1,ans.size()-1);
        return true;
        
    }
    long long  nextGreaterElement(int n) {
        vector<int>ans;
        int x=n;
        while(x!=0){
            int lastD=x%10;
            ans.push_back(lastD);
            x=x/10;
        }
        reverse(ans.begin(),ans.end());
       
        bool flag=nextPermutation(ans);
        if(flag==false){
            return -1;
        }
        long long finalAns=0;
        
        for(int i=0;i<ans.size();i++){
            
             finalAns=finalAns*10+ans[i];
        }
       if(finalAns<n || finalAns>INT_MAX){
           return -1;
       }
        return finalAns;        
        
    }
};