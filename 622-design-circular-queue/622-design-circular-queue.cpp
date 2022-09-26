class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;
    MyCircularQueue(int k) {
          arr=new int[k];
          front=-1;
          rear=0;   
          capacity=k;
          size=0;
    }
    
    
    bool enQueue(int value) {
        if(size==capacity) return false;
        
        arr[rear]=value;
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;        
    
        front=(front+1)%capacity;
        size--;
        if(size==0){
            rear=0;
            front=-1;
        }
       
        return true;
    }
    
    int Front() {
        if(isEmpty()!=true){
            return arr[front];
        }
        else{
            return -1;
        }
    }
    
    int Rear() {
         if(isEmpty()!=true){
            return arr[(rear-1 + capacity)%capacity];
        }
        else{
            return -1;
        }
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */