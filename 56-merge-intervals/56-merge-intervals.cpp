#include<vector>
#include<bits/stdc++.h>
#include<stack>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // vector<vector<int>>ans;
        stack<vector<int>>s;
        s.push(intervals[0]);
        int i=1;
        while(i<intervals.size()){
          if(s.top()[1]>=intervals[i][0]){
              s.top()[1]=max(intervals[i][1],s.top()[1]);
              i++;
          }
            else{
                s.push(intervals[i]);
            }
        }
        intervals.clear();
        while(s.size()!=0){
            intervals.push_back(s.top());
            s.pop();
        }
        return  intervals;
        
    }
};