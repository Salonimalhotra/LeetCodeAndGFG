class MovingAverage {
public:
    queue<int>q;
    int capacity;
    int sum;
    MovingAverage(int size) {
        capacity=size;
        sum=0;
    }
    
    double next(int val) {
        double ans;
        if(q.size()<capacity){
                sum+=val;
                q.push(val);
                ans=((double)sum)/q.size();
        }
        
        else if(q.size()==capacity){
            sum-=q.front();
            q.pop();
            sum+=val;
            q.push(val);     
            ans=((double)sum)/q.size();
        }
        return ans;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */