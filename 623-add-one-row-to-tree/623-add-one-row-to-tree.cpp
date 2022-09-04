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
    TreeNode * helper(TreeNode * root,int currDepth,int depth,int val){
        if(currDepth>=depth || root==NULL){
            return root;
        }
        
        if(currDepth==depth-1){
            TreeNode * newleftroot=new TreeNode(val);
            TreeNode * newrightroot=new TreeNode(val);
            newleftroot->left=root->left;
            newrightroot->right=root->right;
            root->left=newleftroot;
            root->right=newrightroot;
            return root;
        }
        
        root->left=helper(root->left,currDepth+1,depth,val);
        root->right=helper(root->right,currDepth+1,depth,val);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode * newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        return helper(root,1,depth,val);
    }
};