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
    void helper(TreeNode * root,TreeNode *&prev){      
            if(root==NULL){
                return;
            }
            
            helper(root->right,prev);
            helper(root->left,prev);
            
            root->right=prev;
            root->left=NULL;
            
            prev=root;
        
        
        return;
    }
    void flatten(TreeNode* root) {
        // first approach is with recursion here the order of linked list is root->left->right
        // but if we do preorder traversal then we wont be able to get to attatch left subtree ka end to right subtree ka first node
        // but here reverse postorder might work
        // so lets start with it 
        TreeNode * prev=NULL;
        helper(root,prev);
        return;
    }
    
};