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
    void helper(TreeNode * root,vector<int>&inorder){
      if(root==NULL) return;
      helper(root->left,inorder);
      inorder.push_back(root->val);
      helper(root->right,inorder);
      return;
    }
    TreeNode * solve(vector<int>&inorder,int s,int e){
      if(s>e) return NULL;
       int mid=(s+e)/2;
      TreeNode * root=new TreeNode(inorder[mid]);
      root->left=solve(inorder,s,mid-1);
      root->right=solve(inorder,mid+1,e);
      return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
       helper(root,inorder);
       return solve(inorder,0,inorder.size()-1);
    }
};