#include<vector>
#include<string>
#include<queue>
#include<map>
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int>maxHeap;
        map<int,int>map;
        for(int i=0;i<score.size();i++){
            maxHeap.push(score[i]);
        }
        int rank=1;
        while(maxHeap.size()!=0){
            int topElement=maxHeap.top();
            maxHeap.pop();
            map[topElement]=rank;
            rank++;
            
        }
        vector<string>ans;
        for(int i=0;i<score.size();i++){
            int rank=map[score[i]];
            string s=to_string(rank);
            if(s=="1"){
                s="Gold Medal";
            }
            else if(s=="2"){
                s="Silver Medal";
            }
            else if(s=="3"){
                s="Bronze Medal";
            }
            ans.push_back(s);
        }
        return ans;
        
    }
};