class MyStack {
public:
    queue<int>fq;
    queue<int>sq;
    int size;
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        if(fq.size()==0){
            fq.push(x);
            return;
        }
        else{
            while(fq.size()!=0){
                sq.push(fq.front());
                fq.pop();
            }
            
            fq.push(x);
            while(sq.size()!=0){
                 fq.push(sq.front());
                 sq.pop();
            }
        }
    }
    
    int pop() {
        if(fq.size()==0){
            return -1;
        }
        int topElement=fq.front();
        fq.pop();
        return topElement;
    }
    
    int top() {
        return fq.front();
    }
    
    bool empty() {
        if(fq.size()!=0){
            return false;
        }
        else{
            return true;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */