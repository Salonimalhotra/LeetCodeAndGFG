/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int odd=1;
        while(q.size()!=0){
            int t=q.size();
            vector<int>v;
            while(t--){              
                TreeNode * top=q.front();
                q.pop();
                if(top->left!=NULL){
                    q.push(top->left);
                    v.push_back(top->left->val);
                }
                if(top->right!=NULL){
                    q.push(top->right);
                    v.push_back(top->right->val);
                }
              }
               if (odd && q.size()!=0){
                     t=q.size();
                     int i= v.size()-1;
                    while(t--){
                          TreeNode * top=q.front();
                          q.pop(); 
                          top->val=v[i--];
                          q.push(top);
                    }
               }
            
            odd=1-odd;
       }
        return root;
}
        
        
};