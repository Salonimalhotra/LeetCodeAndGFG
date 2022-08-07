// #include<unordered_map>
// #include<string>
class Solution {
public:
// //     int solve(string s,int k,char x,int idx,unordered_map<string,int>&map){
// //         if(idx==s.size()){
// //            return 0;
// //         }
        
// //         string key="";
// //         key.push_back(x);
// //         key.push_back(' ');
// //         key.append(to_string(idx));
// //         if(map.find(key)!=map.end()){
// //             return map[key];
// //         }
        
// //         if(x=='&' || abs(s[idx]-x)<=k){
// //             int option1=1+solve(s,k,s[idx],idx+1,map);
// //             int option2=solve(s,k,x,idx+1,map);
// //              map[key]=max(option1,option2);
            
// //         }
// //         else{
// //                 int option1=solve(s,k,s[0],idx+1,map);
// //                 int option2=solve(s,k,x,idx+1,map);
// //                  map[key]=max(option1,option2);
            
// //         }
// //         return map[key];
// //     }
//     int longestIdealString(string s, int k) {
//         unordered_map<string,int>map;
//         return solve(s,k,'&',0,map);
//         // int * dp=new int[s.size()];
//         // dp[0]=1;
//         // int maxAns=1;
//         // for(int i=1;i<s.size();i++){
//         //     dp[i]=1;
//         //     for(int j=i-1;j>=0;j--){
//         //         if(abs(s[j]-s[i])<=k && dp[j]+1>dp[i]){
//         //             dp[i]=dp[j]+1;
//         //             maxAns=max(maxAns,dp[i]);
//         //         }
//         //     }
//         // }
//         // return maxAns;
//     }
// };
// we are using the lowest common subsequence code  but slightly modified it by checking the condition 
// if absolute difference between current and last character is <= k then only taking 
// the current character else not taking the current character 

int func(int i,char last,string &s,int k,vector<vector<int>> &dp)
{
    if(i<0)    return 0;
		
    int l;
    if(last=='$')
        l = 26;
    else
        l = last-'a';
    
    if(dp[i][l]!=-1)
        return dp[i][l];
    
    int notTake = func(i-1,last,s,k,dp);
    
    int take = 0;
    if(last=='$')     // if current element is the first element then  (since last == $') we can take any element without checking anything
	{
        take = 1+func(i-1,s[i],s,k,dp);
    }
	else if( abs(last-s[i])<=k )
    {
		take = 1+func(i-1,s[i],s,k,dp);
    }
	
    return dp[i][l] = max(take,notTake);
}

int longestIdealString(string s, int k) 
{
    int n =s.size();
    vector<vector<int>> dp(n+1,vector<int>(27,-1));
    char last='$';              // using '$' symbol when initially no elements are taken 

    return func(n-1,last,s,k,dp);   
}

// if you found this helpful pls upvote
// if you are still not able to understand this code then dont be sad , firstly understand finding LCS problem then you will be able
//to understand this completely :)
};