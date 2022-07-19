#include<vector>
#include<unordered_map>
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        vector<double>ans;
        for(int i=0;i<rectangles.size();i++){
            double x=(((double)(rectangles[i][0]))/rectangles[i][1]);
              ans.push_back(x);
        }
        
        unordered_map<double,int>map;
        for(int i=0;i<ans.size();i++){
            map[ans[i]]++;
        }
        
        long long ans1=0;
        for(auto i:map){
            long long x=(((long long )(i.second))* (i.second-1))/2;
            ans1+=x;
        }
        
        return ans1;
        
    }
};