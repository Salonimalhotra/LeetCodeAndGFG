class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(),dominoes.end());
        for(int i=0;i<dominoes.size();i++){
            sort(dominoes[i].begin(),dominoes[i].end());
        }
         sort(dominoes.begin(),dominoes.end());
        for(int i=0;i<dominoes.size();i++){
            cout<<dominoes[i][0]<<" "<<dominoes[i][1]<<endl;
        }
        int ans=0;
        int i=0;
        while(i<dominoes.size()){
            int cnt=1;
            while(i+1<dominoes.size() && dominoes[i+1]==dominoes[i]){
                i++;
                cnt++;
            }
            if(cnt>1)ans+=(cnt * (cnt-1))/2;
            i++;
            
        }
        return ans;
    }
};