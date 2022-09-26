class helper{
  public:
  bool operator()(pair<int,string>option1,pair<int,string>option2){
      if(option1.first>option2.first){
          return true;
      }
      else if(option1.first==option2.first){
          if(option1.second<option2.second){
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
class helper1{
  public:
  bool operator()(pair<int,string>option1,pair<int,string>option2){
      if(option1.first<option2.first){
          return true;
      }
      else if(option1.first==option2.first){
          if(option1.second>option2.second){
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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        // first step is to basically get the frequency of the strings
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
       
        // second step is to get a priority_queue having the min priority queue
        priority_queue<pair<int,string>,vector<pair<int,string>>,helper>pq;
        for(auto i:mp){
            if(pq.size()<k){
                pq.push(make_pair(i.second,i.first));
            }
           else if(pq.size()==k){
                 pq.push(make_pair(i.second,i.first));
                 pq.pop();
           }
        }
        vector<string>ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>,helper1>pq1;
        
       while(pq.size()!=0){
           pq1.push(pq.top());
           pq.pop();
       }        
        
        while(pq1.size()!=0){
            ans.push_back(pq1.top().second);
            pq1.pop();
        } 
        
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};