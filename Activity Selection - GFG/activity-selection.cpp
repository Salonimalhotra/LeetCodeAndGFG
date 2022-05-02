// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    bool static compare(pair<int,int>p1,pair<int,int>p2){
        return p1.second<p2.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            pair<int,int>p=make_pair(start[i],end[i]);
            arr.push_back(p);
            
        }
        sort(arr.begin(),arr.end(),compare);
        // for(int i=0;i<n;i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        
        int max_act=1;
        int i=1;
        int endtime=arr[0].second;
        while(i<n){
            if(arr[i].first>endtime){
                max_act++;
                endtime=arr[i].second;
            }
            i++;
        }
        return max_act;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends