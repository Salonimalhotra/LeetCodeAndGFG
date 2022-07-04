// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include<unordered_map>
class Solution{
public:
    int helper(string S,int i,int j,bool isTrue, unordered_map<string,int>&map){
        int mod = 1003;
        if(i>j){
            return 0;
        }
        
        else if(i==j){
            if(isTrue==true){
               if(S[i]=='T'){
                   return 1;
               }
               else{
                   return 0;
               }
            }
            else if(isTrue==false){
                if(S[i]=='F'){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        
        string temp=to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        
        if(map.find(temp)!=map.end()){
            return map[temp];
        }
        
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2){
            int leftTrue=helper(S,i,k-1,true,map);
            int rightTrue=helper(S,k+1,j,true,map);
            int leftFalse=helper(S,i,k-1,false,map);
            int rightFalse=helper(S,k+1,j,false,map);
            
            char operation=S[k];
            if(operation=='|'){
                if(isTrue==true){
                    ans+=leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
                }
                else{
                    ans+=leftFalse * rightFalse;
                }
            }
            
            else if(operation=='&'){
                if(isTrue==true){
                    ans+=leftTrue * rightTrue;
                }
                else{
                    ans+=leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
                }
            }
            
            else if(operation=='^'){
                if(isTrue==true){
                    ans+=leftFalse * rightTrue + rightFalse * leftTrue;
                }
                else{
                    ans+=leftFalse * rightFalse + leftTrue * rightTrue;
                }
            }
        }
        map[temp]=ans%mod;
        return ans%mod;
    }
    int countWays(int N, string S){
        // code here
        unordered_map<string,int>map;
        return helper(S,0,S.size()-1,true,map);
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