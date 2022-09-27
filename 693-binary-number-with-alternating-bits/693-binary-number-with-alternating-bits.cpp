class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int>temp;
        while(n!=0){
            temp.push_back(n%2);
            n=n/2;
        }
        
        for(int i=0;i<temp.size();i++){
            if(i+1<temp.size() && temp[i+1]==temp[i]) return false;
        }
        return true;
    }
};