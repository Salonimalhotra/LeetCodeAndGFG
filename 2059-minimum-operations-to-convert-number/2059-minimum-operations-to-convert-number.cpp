class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // as we have to find minimum operations we can also use a BFS Approach 
        queue<int>q;
        unordered_set<int>set;
        int steps=0;
        q.push(start);
        // set.insert(start);
        while(q.size()!=0){
            int s=q.size();
            while(s--){
                int top=q.front();
                q.pop();                
               
                if(top==goal){
                    return steps;
                }
                
                 if(top<0 || top>1000 || set.find(top)!=set.end()){
                    continue;
                }                 
                
                else{
                    set.insert(top);
                }
                
                for(int i=0;i<nums.size();i++){
                    int x=top + nums[i];
                    int y=top ^ nums[i];
                    int z=top - nums[i];
                    q.push(x);      
                    q.push(y);      
                    q.push(z);                 
                                       
                }                
                // s--;      
                
            }
            steps++;
        
        }        
        return -1;
        
    }
};