class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         vector<uint32_t>v;
        for(int i=0;i<32;i++){
            uint32_t m= 1<<i;
            if(n & m) v.push_back(1);
            else{
                v.push_back(0);
            }
            
        }
       uint32_t ans=0;
        for(int i=0;i<v.size();i++){
            ans+= pow(2,31-i) * v[i];
        }
        return ans;
    }
};