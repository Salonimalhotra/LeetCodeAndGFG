#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>map;
        int i=0;
        int j=0;
        int count=0;
        while(j<fruits.size()){
           map[fruits[j]]++;
            
          if(map.size()<=2){
              count=max(count,j-i+1);
              j++;
          }  
          
          else if(map.size()>2){              
              while(map.size()>2){
                 map[fruits[i]]--;
                  if(map[fruits[i]]==0){
                      map.erase(fruits[i]);
                      
                  }
                  i++;
               }
              j++;
           }  
        }
        return count;
        
    }
};