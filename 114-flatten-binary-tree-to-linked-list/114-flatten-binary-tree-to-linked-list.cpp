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
    void flatten(TreeNode* root) {
        // time complexity :- O(N) && space complexity is O(1);
        // approach used is morris traversal
        TreeNode * curr=root;        
        while(curr!=NULL){            
            if(curr->left!=NULL){ 
                 TreeNode * prev=curr->left;  
                     while(prev!=NULL && prev->right!=NULL){
                     prev=prev->right;
                     }
                
             prev->right=curr->right;
             curr->right=curr->left; 
             curr->left=NULL;   
           }            
            curr=curr->right;
        }        
        return;
            
    }
};