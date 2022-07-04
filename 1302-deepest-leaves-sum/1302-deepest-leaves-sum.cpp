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
    int getHeight(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        else if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        return max(leftHeight,rightHeight)+1;
    }
    void helperPrint(TreeNode * root,int depth,int &sum){
        if(depth<0){
            return;
        }
        if(root==NULL){
            return;
        }
        if(depth==0 && root->left==NULL && root->right==NULL){
            sum+=root->val;
            return;
        }
        helperPrint(root->left,depth-1,sum);
        helperPrint(root->right,depth-1,sum);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxheight=getHeight(root);
        int sum=0;
        helperPrint(root,maxheight-1,sum);   
        return sum;
    }
};