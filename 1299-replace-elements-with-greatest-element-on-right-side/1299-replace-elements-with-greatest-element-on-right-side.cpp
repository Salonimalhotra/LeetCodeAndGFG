class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int>s;
        
        s.push(arr[arr.size()-1]);
        arr[arr.size()-1]=-1;
        int i=arr.size()-2;
        while(i>=0){
            if(s.size()!=0){
                int topElement=s.top();
                if(arr[i]>topElement){
                    s.push(arr[i]);
                }
                arr[i]=topElement;
            }
            i--;
        }
        
        return arr;
    }
};