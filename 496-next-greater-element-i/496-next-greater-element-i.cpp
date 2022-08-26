class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp2;
        stack<int>s1;
        s1.push(nums2[nums2.size()-1]);
        
        mp2[nums2[nums2.size()-1]]=-1;
        int i=nums2.size()-2;
        
        while(i>=0){
           if(s1.size()==0){
               mp2[nums2[i]]=-1;
               i--;
           }    
            else if(s1.top()>nums2[i]){
                mp2[nums2[i]]=s1.top();
                s1.push(nums2[i]);
                i--;
            }
            
            else if(s1.top()<nums2[i]){
                while(s1.size()!=0 && s1.top()<nums2[i]){
                    s1.pop();
                }
                if(s1.size()==0){
                    s1.push(nums2[i]);
                      mp2[nums2[i]]=-1;
                    i--;
                }
                else{
                    mp2[nums2[i]]=s1.top();
                    s1.push(nums2[i]);
                    i--;
                }
            }
        }
        
        vector<int>ans1;
        for(int i=0;i<nums1.size();i++){
            if(mp2.find(nums1[i])==mp2.end()){
                continue;
            }
            else{
                ans1.push_back(mp2[nums1[i]]);
            }
        }
        return ans1;
    }
};