class cmp{
  public:
  bool operator()(pair<int,int>p1,pair<int,int>p2){
      if(p1.first<p2.first){
          return true;
      }
      else if(p1.first==p2.first){
          if(p1.second<p2.second){
              return true;
          }
          else{
              return false;
          }
      }
      else{
          return false;
      }
  }
};
class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(make_pair(abs(arr[i]-x),arr[i]));            
            if(pq.size()>k)pq.pop();
        }
        
        while(pq.size()!=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};