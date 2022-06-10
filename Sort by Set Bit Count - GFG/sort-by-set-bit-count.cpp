// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
   bool static compare(pair<int,int>p1,pair<int,int>p2){
        return p1.second>p2.second;
    }
    int count(int n){
        int cnt=0;
        while(n>0){
            int x=n&1;
            if(x==1){
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            pair<int,int>p1;
            p1.first=arr[i];
            p1.second=count(arr[i]);
            v.push_back(p1);
        }
        
        stable_sort(v.begin(),v.end(),compare);
        for(int i=0;i<v.size();i++){
            arr[i]=v[i].first;
        }
        return;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends