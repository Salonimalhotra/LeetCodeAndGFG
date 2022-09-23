class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
           cap=k;
           int cnt=0;
          for(int i=0;i<nums.size();i++){
              if(cnt!=k) {
                  pq.push(nums[i]);
                  cnt++;
              }
              else{
                  // cnt++;
                  if(nums[i]>pq.top()){
                      pq.pop();
                      pq.push(nums[i]);
                  }
                  else{
                      continue;
                  }
                  
              }
          }
        
    }
    
    int add(int val) {
        if(pq.size()!=0 && pq.size()==cap){
          if(pq.top()<val){
              pq.pop();
              pq.push(val);
              
          }
           return pq.top();
        }
        else if(pq.size()<cap){
            pq.push(val);
            if(pq.size()==cap){
                return pq.top();
            }
           
        }
        
       return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */