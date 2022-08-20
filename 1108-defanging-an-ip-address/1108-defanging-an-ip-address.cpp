class Solution {
public:
    string defangIPaddr(string address) {
        if(address.size()==0){
            return address;
        }
        string ans;
        string smallAns=defangIPaddr(address.substr(1));
        if(address[0]!='.'){
           ans=address[0] + smallAns;
        }
        else if(address[0]=='.'){
            ans="[.]" + smallAns;
        }
        return ans;
    }
};