class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxHeap;
        for(int i=0;i<piles.size();i++){
            maxHeap.push(piles[i]);
        }
        
        while(k>0){
            int x=maxHeap.top();
            maxHeap.pop();
            x=x-floor(x/2);
            maxHeap.push(x);
            k--;
        }
        
        int ans=0;
        while(maxHeap.size()!=0){
            ans+=maxHeap.top();
            maxHeap.pop();
        }
        
        return ans;
    }
};