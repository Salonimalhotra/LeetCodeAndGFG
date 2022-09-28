class Solution {
public:
    int findComplement(int num) {
        vector<int>v;
        while(num!=0){
            if((num & 1)==1)v.push_back(0);
            else{
                v.push_back(1);
            }
            num=num>>1;
        }
        int finalans=0;
        for(int i=0;i<v.size();i++){
            finalans+=pow(2,i) * v[i];
        }
        return finalans;
    }
};