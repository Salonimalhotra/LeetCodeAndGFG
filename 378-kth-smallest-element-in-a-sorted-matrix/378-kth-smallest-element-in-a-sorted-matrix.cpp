#include<vector>
#include<queue>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>maxHeap;
        int count=0;
        for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
               if(count<k){
                   maxHeap.push(matrix[i][j]);
                   count++;
               }
               else if(count>=k){
                   if(maxHeap.top()>matrix[i][j]){
                       maxHeap.pop();
                       maxHeap.push(matrix[i][j]);
                   }
                   count++;
               }
           }
        }
        return maxHeap.top();        
    }
};