class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
           priority_queue<pair<int,pair<int,int>>>pq;
           for(int i=0;i<k;i++){
               int first_p=points[i][0];
               int second_p=points[i][1];
               int distance=(first_p) * (first_p)  +  (second_p) * (second_p);
               pq.push(make_pair(distance,make_pair(first_p,second_p)));              
               
           }
        
          for(int i=k;i<points.size();i++){
                  int first_p=points[i][0];
                  int second_p=points[i][1];
                  int distance=(first_p) * (first_p)  +  (second_p) * (second_p);
              
                  if(pq.top().first>distance){
                      pq.pop();
                      pq.push(make_pair(distance,make_pair(first_p,second_p)));              
                  }
          } 
          vector<vector<int>>ans;
        
        while(pq.size()!=0){
            int firstp=pq.top().second.first;
            int secondp=pq.top().second.second;
            pq.pop();
            vector<int>ans1;
            ans1.push_back(firstp);
            ans1.push_back(secondp);
            ans.push_back(ans1);
        }
        
        return ans;
          
    }
};