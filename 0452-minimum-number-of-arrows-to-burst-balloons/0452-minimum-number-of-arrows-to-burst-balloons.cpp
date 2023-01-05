class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;

        sort(points.begin(), points.end(), [](auto &a, auto &b){
            if(a[1] < b[1]) return true;
            return false;
        });
        
        int res = 1;
        int shoot = points[0][1];
        for(auto p: points){
            
            if(p[0] > shoot){  
                shoot = p[1];
                res += 1;
            }
        }
        return res;
    }
};