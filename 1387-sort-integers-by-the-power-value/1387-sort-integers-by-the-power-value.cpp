#include<bits/stdc++.h>
class Solution {
public:
//     int solve(int n){
//         if(n==1){
//             return 0;
//         }
        
//         int option1=INT_MAX-1;
//         if(n/2>=0){
//             option1=1 + solve(n/2);            
//         }        
//         return min(option1,1+solve(3*n+1));
//     }
    bool static cmp(pair<int,int>p1,pair<int,int>p2){
        if(p1.second<p2.second){
            return true;
        }
        else if(p1.second==p2.second){
              if(p1.first<p2.first){
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
    int solve(int x){
        if(x==1){
            return 0;
        }
        if(x%2==0){
            return 1 + solve(x/2);
        }
        else{
            return 1 + solve(3 * x +1);
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>arr;
        for(int i=lo;i<=hi;i++){
            pair<int,int>p1;
            p1.first=i;
            p1.second=0;
            arr.push_back(p1);
        }
        for(int j=0;j<arr.size();j++){
            int fv=arr[j].first;
            int ans=solve(fv);
            arr[j].second=ans;
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }
        sort(arr.begin(),arr.end(),cmp);
        return arr[k-1].first;        
    }
};