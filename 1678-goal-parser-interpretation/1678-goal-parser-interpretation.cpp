class Solution {
public:
    string interpret(string command) {
        string ans="";
        for(int i=0;i<command.size();){
          if(command[i]=='G'){
            ans.push_back('G');
            i++;
          }
          else if(command[i]=='(' && command[i+1]==')'){
            ans.push_back('o');
            i+=2;
          }
          else if(command[i]=='(' && command[i+1]=='a'){
            ans.push_back('a');
            ans.push_back('l');
            i+=4;
          }
        }
      return ans;
    }
};