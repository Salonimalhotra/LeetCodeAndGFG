// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static compare(pair<pair<int,int>,int>p1,pair<pair<int,int>,int>p2){
        if(p1.first.second<p2.first.second){
            return true;
        }
        else if(p1.first.second>p2.first.second){
            return false;
        }
        else if(p1.second<p2.second){
            return true;
        }
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
       vector<pair<pair<int,int>,int>>arr;
       for(int i=0;i<n;i++){
           pair<pair<int,int>,int>p1=make_pair(make_pair(start[i],end[i]),i);
           arr.push_back(p1);
       }
      sort(arr.begin(),arr.end(),compare);
    //   for(int i=0;i<arr.size();i++){
    //       cout<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<endl;
    //   }
      
    int i=1;
    int count=1;
    int endTime=arr[0].first.second;
    while(i<n){
        if(arr[i].first.first>endTime){
            count++;
            endTime=arr[i].first.second;
            i++;
        }
        else{
            i++;
            
        }
    }
    return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends