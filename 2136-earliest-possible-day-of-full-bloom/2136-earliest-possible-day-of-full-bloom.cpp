class Solution {
public:
    bool static cmp(pair<int,int>&p1,pair<int,int>&p2){
      if(p1.second>p2.second){
        return true;
      }
      else{
        return false;
      }
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v;
        for(int i=0;i<plantTime.size();i++){
          pair<int,int>p;
          p={plantTime[i],growTime[i]};
          v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);
        int time=0;
        int maxTime=INT_MIN;
        for(int i=0;i<v.size();i++){
          time+=v[i].first;
          maxTime=max(maxTime,time + v[i].second);
        }   
      return maxTime;
    }
};