class Solution {
public:
    bool static cmp(vector<int>a1,vector<int>a2){
        if(a1[1]>a2[1]){
            return true;
        }
        else{
            return false;
        }
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        // for(int i=)
        int maxAns=0;
        int cnt=0;
        int i=0;
        while(cnt<=truckSize && i<boxTypes.size()){
            if(cnt+boxTypes[i][0]<=truckSize){
                cnt+=boxTypes[i][0];
                maxAns+=(boxTypes[i][0] * boxTypes[i][1]);
            }
            else{
                int temp=(truckSize-cnt) * boxTypes[i][1];
                // cout<<truckSize-cnt<<endl;
                cnt+=(truckSize-cnt);          
                // cout<<(truckSize-cnt) * boxTypes[i][1];
                maxAns+=temp;
                break;
            }
            i++;
        }
        return maxAns;
    }
};