class Solution {
public:
    string defangIPaddr(string address) {
        if(address.size()==0){
            return address;
        }
        string ans;
        if(address[0]!='.'){
            string smallAns=defangIPaddr(address.substr(1));
           ans=address[0] + smallAns;
        }
        else if(address[0]=='.'){
            ans="[.]" + defangIPaddr(address.substr(1));
        }
        return ans;
    }
};