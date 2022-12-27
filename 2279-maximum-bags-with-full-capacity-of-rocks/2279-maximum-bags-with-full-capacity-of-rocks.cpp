class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diff;
        for(int i=0;i<capacity.size();i++){
          int difference=capacity[i]-rocks[i];
          diff.push_back(difference);
        }
        sort(diff.begin(),diff.end());
         for(auto i:diff){
           cout<<i<<" , ";
         }
        int maximumBags=0;
        int i=0;
        while(i<diff.size()){
          if(diff[i]==0){
            maximumBags++;
            i++;
          }
          else if(additionalRocks>=diff[i]){
            maximumBags++;
            additionalRocks-=diff[i];
            i++;
          }
          else{
            break;
          }
        }
        return maximumBags;
    }
};