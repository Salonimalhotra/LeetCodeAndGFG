#include<vector>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=1;
        int i;
        for(i=0;i<digits.size();i++){
            if(carry==1){
                if(digits[i]<9){
                    digits[i]=digits[i]+1;
                    carry=0;
                }
                else if(digits[i]==9){
                    digits[i]=0;
                    continue;
                }
            }
            
        }
        if(i==digits.size() && carry==1){
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;        
    }
};