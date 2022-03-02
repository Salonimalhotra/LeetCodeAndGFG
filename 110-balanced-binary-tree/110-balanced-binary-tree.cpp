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
class pair1{
  public:
  bool isBalanced1;
  int height;
};
class Solution {
public:
    pair1 helper(TreeNode * root){
        if(root==NULL){
            pair1 ans;
            ans.isBalanced1=true;
            ans.height=0;
            return ans;
        }
        pair1 finalAns;
        pair1 LeftAns=helper(root->left);
        pair1 RightAns=helper(root->right);
        
        if(LeftAns.isBalanced1==true && RightAns.isBalanced1==true && abs(LeftAns.height-RightAns.height)<=1){
            finalAns.isBalanced1=true;
        }
        else{
            finalAns.isBalanced1=false;
        }
        finalAns.height=1+max(LeftAns.height,RightAns.height);
        return finalAns;
    }
    bool isBalanced(TreeNode* root) {
        pair1 ans=helper(root);
        return ans.isBalanced1;
    }
};