#include<string>
class Solution {
public:
    int countAsterisks(string s) {
        int count=0;
        int numberBrackets=0;
        for(auto i:s){
            if(numberBrackets==0 && i=='*'){
                count+=1;
            }
            else if(i=='|' && numberBrackets==0){
                numberBrackets=1;
            }
            else if(i=='|' && numberBrackets==1){
                numberBrackets=0;
            }
            
        }
        return count;        
    }
};