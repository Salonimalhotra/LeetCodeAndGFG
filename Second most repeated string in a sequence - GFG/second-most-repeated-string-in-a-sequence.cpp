// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<climits>
#include<unordered_map>
class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        int max_f=0;
        for(auto i:map){
            if(i.second>max_f){
                max_f=i.second;
            }
        }
        string final="";
        // int ans=-1;
        int min_diff=INT_MAX;
        for(auto i:map){
            if(i.second<max_f && max_f-i.second<min_diff){
                final=i.first;
                min_diff=max_f-i.second;
            }
        }
        return final;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends