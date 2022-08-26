class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>=2){
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            if(top1==top2){
                continue;
            }
            else{
                pq.push(top1-top2);
            }
        }
        
        int ans;
        if(pq.size()==0){
            ans=0;
        }
        else if(pq.size()==1){
            ans=pq.top();
        }
        return ans;
    }
};