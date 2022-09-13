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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        
        return max(height(root->left),height(root->right)) + 1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL){ 
               return NULL;
        }
        
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        
        if(leftheight==rightheight){
            return root;
        }
        
        else if(leftheight>rightheight){
            return lcaDeepestLeaves(root->left);
        }
        
        else if(leftheight<rightheight){
              return lcaDeepestLeaves(root->right);
        }
        return NULL;
    }
};