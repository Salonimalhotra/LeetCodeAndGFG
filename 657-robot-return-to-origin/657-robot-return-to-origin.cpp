class Solution {
public:
    bool judgeCircle(string moves) {
         unordered_map<char,int>mp;
         for(int i=0;i<moves.size();i++){
             if(moves[i]=='U'){
                 if(mp.find('D')!=mp.end()){
                     mp['D']--;
                     if(mp['D']==0){
                         mp.erase('D');
                     }
                 }
                 else{
                     mp[moves[i]]++;
                 }
             }
             
             if(moves[i]=='D'){
                 if(mp.find('U')!=mp.end()){
                     mp['U']--;
                     if(mp['U']==0){
                         mp.erase('U');
                     }
                 }
                 else{
                     mp[moves[i]]++;
                 }
             }
             
             if(moves[i]=='L'){
                 if(mp.find('R')!=mp.end()){
                     mp['R']--;
                     if(mp['R']==0){
                         mp.erase('R');
                     }
                 }
                 else{
                     mp[moves[i]]++;
                 }
             }
             
             if(moves[i]=='R'){
                 if(mp.find('L')!=mp.end()){
                     mp['L']--;
                     if(mp['L']==0){
                         mp.erase('L');
                     }
                 }
                 else{
                     mp[moves[i]]++;
                 }
             }
         }
        if(mp.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};