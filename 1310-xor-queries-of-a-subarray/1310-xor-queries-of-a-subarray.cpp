class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>x;
        vector<int>prefixArray(arr.size());
        prefixArray[0]=arr[0];
        for(int i=1;i<arr.size();i++){
          prefixArray[i]=(arr[i] ^ prefixArray[i-1]);
        }
       
        for(int i=0;i<queries.size();i++){
          int firstP=queries[i][0];
          int secondP=queries[i][1];
          
          int ans=prefixArray[secondP];
          if(firstP-1>=0) ans=ans  ^ prefixArray[firstP-1];
          x.push_back(ans);
        }
      return x;
    }
};