#include<vector>
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res='#';
        int s=0;
        int target_code=target;
        int e=letters.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(letters[mid]==target){
                s=mid+1;
            }
            else if(letters[mid]>target){
                res=letters[mid];
                e=mid-1;
            }
            else if(letters[mid]<target){
                s=mid+1;
            }
        }
        
       if(res=='#'){    
        int s=0;
        // int target_code=target;
        int e=letters.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(letters[mid]==target){
                e=mid-1;
            }
            else if(letters[mid]<target ){
                res=letters[mid];
                 e=mid-1;
            }
            else if(letters[mid]>target){
                e=mid-1;
            }
            
         }
        }
        return res;
    }
};