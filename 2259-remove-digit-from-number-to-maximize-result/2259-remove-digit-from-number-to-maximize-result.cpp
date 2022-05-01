#include<string>
class Solution {
public:
    int lastDigit(string number,char x){
       if(number.size()==0){
           return -1;
       }
       int lastOcc=lastDigit(number.substr(1),x);
        if(lastOcc!=-1){
          return 1+lastOcc;
        }
        if(number[0]==x){
            return 0;
        }
        return -1;
    }
    int getInteger(char x){
        return x-'0';
        }
    string removeDigit(string number, char digit) {
        for(int i=0;i<number.size()-1;i++){
             if(number[i]==digit){
                 if(getInteger(number[i])<getInteger(number[i+1])){
                     return number.substr(0,i)+number.substr(i+1);
                 }
             }
        }
        int lastOccIndex=lastDigit(number,digit);
        return number.substr(0,lastOccIndex)+number.substr(lastOccIndex+1);
    }
};