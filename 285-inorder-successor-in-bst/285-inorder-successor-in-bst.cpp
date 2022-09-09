/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode * root,vector<TreeNode *>&arr1){
    if(root==NULL){
       return;
    }
    
    helper(root->left,arr1);
    arr1.push_back(root);
    helper(root->right,arr1);
    return;
}
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode *>arr1;
        helper(root,arr1);
        int i=0;
        for(i=0;i,arr1.size();i++){
            if(arr1[i]==p){
                break;
            }
        }
        
        if(i==arr1.size()-1){
            return NULL;
        }
        else{
            return arr1[i+1];
        }
    }
};