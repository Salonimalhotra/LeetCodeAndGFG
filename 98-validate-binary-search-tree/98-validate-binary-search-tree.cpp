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
class Pair{
  public:
  bool isBST;
  int maximumValue;
  int minimumValue;
};
class Solution {
public:
    Pair helper(TreeNode * root){
        if(root==NULL){
            Pair ans;
            ans.isBST=true;
            ans.maximumValue=INT_MIN;
            ans.minimumValue=INT_MAX;
            return ans;
        }
        else if(root->left==NULL && root->right==NULL){
            Pair ans;
            ans.isBST=true;
            ans.maximumValue=root->val;
            ans.minimumValue=root->val;
            return ans;
        }
        else if(root->left==NULL && root->right!=NULL){          
             Pair rightAns=helper(root->right);
             Pair finalAns;
             if(rightAns.minimumValue>root->val && rightAns.isBST==true){
                 finalAns.isBST=true;
             }
             else{
                 finalAns.isBST=false;
             }
             finalAns.minimumValue=min(root->val,rightAns.minimumValue);
             finalAns.maximumValue=max(root->val,rightAns.maximumValue);
             return finalAns;   
        }
        
     else if(root->left!=NULL && root->right==NULL){
              Pair leftAns=helper(root->left);
              Pair finalAns;
              if(leftAns.maximumValue<root->val && leftAns.isBST==true){
                 finalAns.isBST=true;
              }
              else{
                 finalAns.isBST=false;
              }
              finalAns.minimumValue=min(root->val,leftAns.minimumValue);
              finalAns.maximumValue=max(root->val,leftAns.maximumValue);
              return finalAns;   
        }
        
        else{
        Pair leftAns=helper(root->left);
        Pair rightAns=helper(root->right);
        Pair finalAns;
        if(leftAns.maximumValue<root->val && rightAns.minimumValue>root->val &&             leftAns.isBST==true && rightAns.isBST==true){
            finalAns.isBST=true;
        }
        else{
            finalAns.isBST=false;
        }
        finalAns.minimumValue=min(root->val,min(leftAns.minimumValue,rightAns.minimumValue));
        finalAns.maximumValue=max(root->val,max(leftAns.maximumValue,rightAns.maximumValue));
        return finalAns;
        }
        
        
    }
    bool isValidBST(TreeNode* root) {
        
        Pair ans=helper(root);
        return ans.isBST;        
    }
};