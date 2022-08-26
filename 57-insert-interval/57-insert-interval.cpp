class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)      {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<< "  " <<intervals[i][1]<<endl;
        }
         int index=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=intervals[index][1]){
                intervals[index][1]=max(intervals[index][1],intervals[i][1]);
               
            }
            else {
                index++;
                intervals[index][0]=intervals[i][0];
                intervals[index][1]=intervals[i][1];
                
            }
        }
        
        for(int i=intervals.size()-1;i>index;i--){
            intervals.pop_back();
        }
        return intervals;
    }
};