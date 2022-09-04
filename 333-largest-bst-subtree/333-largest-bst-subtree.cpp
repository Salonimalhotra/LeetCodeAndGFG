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
class Helper{
  public:
  bool isBST;
  int minValue;
  int maxValue;
  int size;
};
class Solution {
public:
    Helper solve(TreeNode * root){
        if(root==NULL){
            Helper ans;
            ans.isBST=true;
            ans.minValue=INT_MAX;
            ans.maxValue=INT_MIN;
            ans.size=0;
            return ans;
        }
                
        Helper leftAns=solve(root->left);
        Helper rightAns=solve(root->right);
        
        Helper finalAns;
        finalAns.isBST= leftAns.isBST && rightAns.isBST && leftAns.maxValue<root->val && rightAns.minValue>root->val;
        finalAns.minValue=min(root->val,min(leftAns.minValue,rightAns.minValue));
        finalAns.maxValue=max(root->val,max(leftAns.maxValue,rightAns.maxValue));
        if(finalAns.isBST){
            finalAns.size=1 + leftAns.size + rightAns.size;
        }
        else{
            finalAns.size=max(leftAns.size , rightAns.size);
        }
        return finalAns;        
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        Helper ans=solve(root);
        return ans.size;
    }
};