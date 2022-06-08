// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<string>
class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s2.size()!=s1.size()){
            return false;
        }
        int i=0;
        int j=0;
        s1=s1+s1;
        // cout<<s1.size()<<endl;
        // cout<<s2.size()<<endl;
        while(i<s1.size()){
            while(i<s1.size() && s1[i]!=s2[j]){
                i++;
            }
            while(i<s1.size() && j<s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }
            // cout<<j<<endl;
            if(j==s2.size()){
                return true;
            }
            else{
                j=0;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends