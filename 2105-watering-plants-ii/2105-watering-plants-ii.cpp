class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i=0;
        int j=plants.size()-1;
        int x=capacityA;
        int y=capacityB;
        int minAns=0;
        while(i<j){           
                if(x>=plants[i]){
                    x-=plants[i];
                    i++;
                }
                else if(x<plants[i]){
                    minAns++;
                    x=capacityA;
                    x-=plants[i];
                    i++;
                }
                
                if(y>=plants[j]){
                    y-=plants[j];
                    j--;
                }
                
                else if(y<plants[j]){
                    minAns++;
                    y=capacityB;
                    y-=plants[j];
                    j--;
                }
            
        }
        
        if(i==j){
            if(max(x,y)<plants[i]){
                minAns++;
            }
        }
        return minAns;
    }
};