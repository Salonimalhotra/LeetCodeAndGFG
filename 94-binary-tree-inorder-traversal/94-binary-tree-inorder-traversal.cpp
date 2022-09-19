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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode * curr=root;
        while(curr!=NULL){
            TreeNode * temp=curr->left;
            if(temp==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
                continue;
            }
            else{
                
              while(temp->right!=NULL && temp->right!=curr){
                temp=temp->right;
               }
              if(temp->right==NULL){
                temp->right=curr;
                curr=curr->left;
              }
            
              else if(temp->right==curr){
                   temp->right=NULL;
                   ans.push_back(curr->val);
                   curr=curr->right;
               }
                
            }
            
        }
        return ans;
    }
};