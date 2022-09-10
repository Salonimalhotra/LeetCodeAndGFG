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
    bool existInTree(TreeNode * root,TreeNode *p){
        if(root==NULL){
            return false;
        }
        if(root->val==p->val){
            return true;
        }
        bool leftAns=existInTree(root->left,p);
        bool rightAns=existInTree(root->right,p);
        return leftAns || rightAns;        
    }
    TreeNode * helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }       
       
       
       if(root->val==p->val || root->val==q->val){
           return root;
       }
            
        TreeNode * leftAns= helper(root->left,p,q);
        TreeNode * rightAns= helper(root->right,p,q);
        
        if(leftAns==NULL && rightAns==NULL){
            return NULL;
        }
        
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else{
            return root;
        }
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }       
       
        if(existInTree(root,p)==false || existInTree(root,q)==false){
            return NULL;
        }
        return helper(root,p,q);
    }
};