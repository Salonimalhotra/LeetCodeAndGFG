#include<bits/stdc++.h>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool check=false;
        for(auto i:wordList){
            if(i==endWord){
                check=true;
                break;
            }
        }
        
        if(check==false){
            return 0;
        }
        unordered_map<string ,bool>map;
        
//         for(int i=0;i<beginWord.size();i++){
//             char x=beginWord[i];
//             for(auto j:wordList){
//                 string test1=beginWord.substr(0,i)+beginWord.substr(i+1);
//                 string test2=j.substr(0,i)+j.substr(i+1);
//                 if(test1==test2 && beginWord[i]!=j[i]){
//                     beginWord=j;
//                     if(j==endWord){
//                         return 
//                     }
                    
//                 }
//             }
//         }
        queue<pair<string,int>>q;
        q.push(make_pair(beginWord,1));
        map[beginWord]=1;
        unordered_set<string>set;
        for(auto j:wordList){
            set.insert(j);
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