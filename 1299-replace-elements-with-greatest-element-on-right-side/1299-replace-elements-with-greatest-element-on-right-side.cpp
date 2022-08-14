class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
//         stack<int>s;
        
//         s.push(arr[arr.size()-1]);
//         arr[arr.size()-1]=-1;
//         int i=arr.size()-2;
//         while(i>=0){
//             if(s.size()!=0){
//                 int topElement=s.top();
//                 if(arr[i]>topElement){
//                     s.push(arr[i]);
//                 }
//                 arr[i]=topElement;
//             }
//             i--;
//         }
        
//         return arr;
        
        int maxElement=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            int curr=arr[i];
            arr[i]=maxElement;
            if(curr>maxElement){
                maxElement=curr;
            }
        }
        return arr;
    }
};