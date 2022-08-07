#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        // long long ans=0;
        unordered_map<int,long long >map;
        long long days=0;
        for(int i=0;i<tasks.size();i++){
            
            if(map.find(tasks[i])==map.end() || days+1-map[tasks[i]]>space){
                days++;
                map[tasks[i]]=days;
                // cout<<"Day "<<days<<": "<<"task exceuted "<<i<<" th task"<<endl;
            }
            else{
                  days++;
                  long long  currentday=days;
//                 while(days-map[tasks[i]]<=space){
//                     days++;
//                     // cout<<"Day "<<days<<": "<<"Take a break"<<endl;  
                    
//                 }
                long long x=space+ 1 + map[tasks[i]]-currentday;
                days+=x;
              
                 // cout<<"Day "<<days<<": "<<"task exceuted "<<i<<" th task"<<endl;
                map[tasks[i]]=days;
            }
        }
        return days;
    }
};