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
  int sum;
  int maxSum;
   bool isbST;
   int maxValue;
   int minValue;
};
class Solution {
public:
    Helper solve(TreeNode * root){
        if(root==NULL){
            Helper ans;
            ans.sum=0;
            ans.maxSum=0;
            ans.isbST=true;
            ans.maxValue=INT_MIN;
            ans.minValue=INT_MAX;
            return ans;
                
        }
        
        Helper leftAns=solve(root->left);
        Helper rightAns=solve(root->right);
        
        Helper finalAns;
        finalAns.maxValue=max(root->val,max(leftAns.maxValue,rightAns.maxValue));
        finalAns.minValue=min(root->val,min(leftAns.minValue,rightAns.minValue));
        if(leftAns.isbST==true && rightAns.isbST==true && leftAns.maxValue<root->val && rightAns.minValue>root->val){
            finalAns.isbST=true;
            finalAns.sum=root->val + leftAns.sum + rightAns.sum;
            finalAns.maxSum=max(finalAns.sum,max(leftAns.maxSum,rightAns.maxSum));
        }
        else{
              finalAns.isbST=false;
             finalAns.sum=root->val + leftAns.sum + rightAns.sum;
             finalAns.maxSum=max(leftAns.maxSum,rightAns.maxSum);
        }        
        return finalAns;   
    }
    int maxSumBST(TreeNode* root) {
        Helper finalAns=solve(root);
        return finalAns.maxSum;
    }
};