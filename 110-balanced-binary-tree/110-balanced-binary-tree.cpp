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
    int Helper(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int Leftheight=Helper(root->left);
        if(Leftheight==-1){
            return -1;
        }
        int Rightheight=Helper(root->right);
        if(Rightheight==-1){
            return -1;
        }
        if(abs(Leftheight-Rightheight)>1){
            return -1;
        }
        return 1+max(Leftheight,Rightheight);
        
    }
    bool isBalanced(TreeNode* root) {
        int ans=Helper(root);
        if(ans!=-1){
            return true;
        }
        else{
            return false;
        }
    }
};