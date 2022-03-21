#include<queue>
class MedianFinder {
public:
     priority_queue<int>maxHeap;
     priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        // priority_queue<int>maxHeap;
        // priority_queue<int,vector<int>,greater<int>>minHeap;
    }
    
    void addNum(int num) {
         if(maxHeap.size() &&  maxHeap.top()<num){
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        
        //making size of both the heaps equal
        if(minHeap.size()>maxHeap.size() && minHeap.size()-maxHeap.size()>1){
            int topElement=minHeap.top();
            minHeap.pop();
            maxHeap.push(topElement);
        }
        else if(minHeap.size()<maxHeap.size() && maxHeap.size()-minHeap.size()>1){
            int topElement=maxHeap.top();
            maxHeap.pop();
            minHeap.push(topElement);
        }
    }
    
    double findMedian() {
         double median=0;
        if(minHeap.size()==maxHeap.size()){
            if(minHeap.size()!=0){
                median+=minHeap.top();
            }
            if(maxHeap.size()!=0){
                median+=maxHeap.top();
            }
            median=median/2;
        }
        
        else if(minHeap.size()>maxHeap.size()){
            median=minHeap.top();
        }
        else if(maxHeap.size()>minHeap.size()){
            median=maxHeap.top();
        }
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */