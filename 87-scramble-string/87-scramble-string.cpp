class Solution {
public:
    bool helper(string s1,string s2,unordered_map<string,bool>&map){
        if(s1.compare(s2)==0){
            return true;
        }
        else if(s1.size()<=1 || s2.size()<=1){
            return false;
        }
        string temp="";
        temp.append(s1);
        temp.push_back(' ');
        temp.append(s2);
        if(map.find(temp)!=map.end()){
            return map[temp];
        }
        
        bool flag=false;
        int n=s1.size();
        for(int i=1;i<=n-1;i++){
            bool condition1=helper(s1.substr(0,i),s2.substr(n-i,i),map) && helper(s1.substr(i,n-i),s2.substr(0,n-i),map);
            bool condition2=helper(s1.substr(0,i),s2.substr(0,i),map) && helper(s1.substr(i),s2.substr(i),map);
            if(condition1==true || condition2==true){
                map[temp]=true;
                return true;
            }
        }
        map[temp]=false;
        return false;
    }
    bool isScramble(string s1, string s2) {
      if(s1.size()!=s2.size()){
          return false;
      }   
      else if(s1.size()==0 && s2.size()==0){
          return true;
      }
      unordered_map<string,bool>map;  
      return helper(s1,s2,map);  
    }
};