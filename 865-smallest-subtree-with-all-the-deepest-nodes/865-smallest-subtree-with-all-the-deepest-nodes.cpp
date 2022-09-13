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
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
    
    void solve(TreeNode * root,unordered_map<int,int>&mp,int maxD,int lvl){
        if(root==NULL){
            return;
        }
        
        if(lvl==maxD && root!=NULL){
            mp[root->val]++;
        }
        
        solve(root->left,mp,maxD,lvl+1);
        solve(root->right,mp,maxD,lvl+1);
        return;
    }
    TreeNode * helper(TreeNode * root,unordered_map<int,int>&mp){
        if(root==NULL){
            return NULL;
        }
        
        else if(root->left!=NULL && root->right!=NULL){
            if(mp.find(root->left->val)!=mp.end() && mp.find(root->right->val)!=mp.end()){
                return root;
            }           
            
        }
        
        else if(root->left==NULL && root->right==NULL){
            if(mp.find(root->val)!=mp.end()){
                return root;
            }
            else{
                return NULL;
            }
        }
        
        TreeNode * leftans=helper(root->left,mp);
        TreeNode * rightans=helper(root->right,mp);
        if(leftans!=NULL && rightans!=NULL){
            return root;
        }
        else if(leftans==NULL){
            return rightans;
        }     
        else if(rightans==NULL){
            return leftans;
        }
        return NULL;
    }
      TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxD=maxDepth(root);
        solve(root,mp,maxD,1);     
        return helper(root,mp);
          
    }
};