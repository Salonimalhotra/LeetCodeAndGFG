// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#include<unordered_map>
#include<bits/stdc++.h>
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    //Brute Force
    //  int maxLen=-1;
    // for(int i=0;i<s.size();i++){
    //     for(int j=i;j<s.size();j++){
    //         unordered_map<char,int>map;
    //         for(int k=i;k<=j;k++){
    //             map[s[k]]++;
    //         }
    //         if(map.size()==k){
    //             maxLen=max(maxLen,j-i+1);
    //         }
    //     }
    // }
    // return maxLen;
    int i=0;
    int maxLen=-1;
    int j=0;
    unordered_map<char,int>map;
      while(j<s.size()){
          map[s[j]]++;
          if(map.size()<k){
             j++;    
          }
          else if(map.size()==k){
              maxLen=max(maxLen,j-i+1);
              j++;
          }
          else if(map.size()>k){
              while(map.size()>k){
                  map[s[i]]--;
                  if(map[s[i]]==0){
                      map.erase(s[i]);
                  }
                  i++;
              }
              j++;
          }
      }
      return maxLen;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends