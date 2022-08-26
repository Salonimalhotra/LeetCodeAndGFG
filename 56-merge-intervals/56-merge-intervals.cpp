class Solution {
public:
//     bool static cmp(pair<int,int>p1,pair<int,int>p2){
//         if(p1.first<p2.first){
//             return true;
//         }
//         else if(p1.first==p2.first){
//             if(p1.second<=p2.second){
//                 return true;
//             }
//             else{
//                 return false;
//             }
            
//         }
//         else{
//             return false;
//         }
//     }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>>v;
        for(int i=0;i<intervals.size();i++){
            pair<int,int>p;
            p.first=intervals[i][0];
            p.second=intervals[i][1];
            v.push_back(p);
        }
        
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        vector<int>v1;
        v1.push_back(v[0].first);
        v1.push_back(v[0].second);
        ans.push_back(v1);
        int last=0;
        // cout<<v1[0]<<endl;
        // cout<<v1[1]<<endl;
        for(int i=1;i<v.size();i++){
            if(ans[last][1]>=v[i].first){
                ans[last][1]=max(v[i].second,ans[last][1]);
            }
            else{
                vector<int>temp;
                temp.push_back(v[i].first);
                temp.push_back(v[i].second);
                ans.push_back(temp);
                last++;
            }
        }
        return ans;
    }
};