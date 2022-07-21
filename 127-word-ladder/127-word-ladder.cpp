#include<bits/stdc++.h>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        unordered_map<string ,bool>map;
        queue<pair<string,int>>q;
        q.push(make_pair(beginWord,1));
        map[beginWord]=1;
        unordered_set<string>set;
        
        for(auto j:wordList){
            set.insert(j);
        }
        
        if(set.find(endWord)==set.end()){
            return 0;
        }
        
        while(q.size()!=0){
            pair<string,int>top=q.front();
            q.pop();
            string top1=top.first;            
            for(int i=0;i<top1.size();i++){
                char x=top1[i];
                for(int j=0;j<=25;j++){
                    char m=j+'a';
                    string tester=top1.substr(0,i)+m+top1.substr(i+1);
                    if(map.find(tester)!=map.end()){
                        continue;
                    }
                    else if(endWord==tester){
                        return top.second+1;
                    }
                    else{
                        bool check=false;
                        if(set.find(tester)!=set.end()){
                            check=true;
                        }
                        if(check==false){
                            continue;
                        }
                        pair<string,int>p1;
                        p1.first=tester;
                        p1.second=top.second+1;
                        map[tester]=1;
                        q.push(p1);
                    }
                }
            }
        }
        
        return 0;
    }
};