class StockSpanner {
    stack<pair<int,int>>s;
    int currIndex;
    public:   
    StockSpanner() {
     currIndex=0;        
    }
    
    int next(int price) {
        int ans=1;
        while(s.size()!=0 && s.top().first<=price){
             s.pop();            
        }
        if(s.size()==0){
            ans=currIndex+1;
            s.push(make_pair(price,currIndex));
        }
        else{
            int temp=currIndex-s.top().second;
            if(temp>ans){
                ans=temp;
            }
            s.push(make_pair(price,currIndex));
        }
        currIndex=currIndex+1;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */