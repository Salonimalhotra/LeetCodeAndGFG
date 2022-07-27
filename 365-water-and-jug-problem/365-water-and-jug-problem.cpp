#include<bits/stdc++.h>
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        if(jug1Capacity+jug2Capacity<targetCapacity){
            return false;
        }        
        unordered_map<int,bool>map;
        queue<int>q;
        q.push(0);
        map[0]=true;
        int dir[4]={+jug1Capacity,-jug1Capacity,+jug2Capacity,-jug2Capacity};
        while(q.size()!=0){
            int curr=q.front();
            q.pop();
            if(curr==targetCapacity){
                return true;
            }
            
            for(int i=0;i<4;i++){
                int newCurr=curr+dir[i];
                
                if(newCurr<0 || newCurr>jug1Capacity+jug2Capacity){
                    continue;
                }
                
                else{
                    if(map.find(newCurr)==map.end()){
                        q.push(newCurr);
                        map[newCurr]=true;
                    }
                }
            }
            
        }
        return false;
        
    }
};