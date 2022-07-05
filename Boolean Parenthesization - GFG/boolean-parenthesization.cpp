// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include<unordered_map>
#include<cmath>
class Solution{
public:
    int solve(string S,int i,int j,bool isTrue,unordered_map<string,int>&map){
        int mod=1003;
        if(i>j){
            return 0;
        }
        
        if(i==j){
            if(isTrue){
                if(S[i]=='T'){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                if(S[i]=='F'){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            
        }
        
        string temp="";
        temp.append(to_string(i));
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        
        if(map.find(temp)!=map.end()){
            return map[temp];
        }
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2){
        
            int leftAnsTrue=solve(S,i,k-1,true,map);
            int leftAnsFalse=solve(S,i,k-1,false,map);
            int rightAnsTrue=solve(S,k+1,j,true,map);
            int rightAnsFalse=solve(S,k+1,j,false,map);
            
            if(S[k]=='&'){
                if(isTrue==true){
                    ans+=leftAnsTrue * rightAnsTrue;
                }
                else{
                    ans+=leftAnsFalse * rightAnsFalse + leftAnsFalse* rightAnsTrue + leftAnsTrue * rightAnsFalse;
                }
            }
            else if(S[k]=='|'){
                   if(isTrue==true){
                      ans+=leftAnsTrue * rightAnsTrue + leftAnsFalse * rightAnsTrue + leftAnsTrue * rightAnsFalse;
                    }
                    else{
                        ans+=leftAnsFalse * rightAnsFalse;
                    }
            }
            else if(S[k]=='^'){
                if(isTrue){
                    ans+=leftAnsFalse * rightAnsTrue + leftAnsTrue * rightAnsFalse;
                }
                else{
                    ans+=leftAnsFalse * rightAnsFalse + leftAnsTrue * rightAnsTrue;
                }
            }
        }
         map[temp]=ans%mod;
         return ans%mod;
    }
    int countWays(int N, string S){
        // code here
        unordered_map<string,int>map;
        map.clear();
        return solve(S,0,S.size()-1,true,map);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends