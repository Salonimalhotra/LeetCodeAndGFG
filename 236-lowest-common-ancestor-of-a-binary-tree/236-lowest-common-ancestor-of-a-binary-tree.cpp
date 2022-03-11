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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        
        TreeNode * lCAleft=lowestCommonAncestor(root->left,p,q);
        TreeNode * lCAright=lowestCommonAncestor(root->right,p,q);
        
        if(lCAleft!=NULL && lCAright!=NULL){
         return root; 
        }
        else if(lCAleft==NULL && lCAright==NULL){
            return NULL;
        }
        else if(lCAleft==NULL && lCAright!=NULL){
           return lCAright;
        }
        else if(lCAleft!=NULL && lCAright==NULL){
          return lCAleft;
        }
        return NULL;
    }
};