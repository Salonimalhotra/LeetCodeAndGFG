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
    int minElement;
    int maxElement;
    int maxDiff;
    
};
class Solution {
public:
    Helper solve(TreeNode * root){
        if(root==NULL){
           Helper p1;
          p1.minElement=INT_MAX;
          p1.maxElement=INT_MIN;
          p1.maxDiff=0;          
          return p1;      
        }
        
         Helper leftAns=solve(root->left);
         Helper rightAns=solve(root->right);
        
         
         Helper finalAns;
        // if(leftAns.minElement)
        int op1=INT_MIN;
        int op2=INT_MIN;
        if(leftAns.minElement!=INT_MAX && leftAns.maxElement!=INT_MIN){
           op1=abs(root->val-leftAns.minElement);
          op2=abs(root->val - leftAns.maxElement);
        }
        int op3=INT_MIN;
        int op4=INT_MIN;
        
        if(rightAns.minElement!=INT_MAX && rightAns.maxElement!=INT_MIN){
           op3=abs(root->val-rightAns.minElement);
           op4=abs(root->val -rightAns.maxElement);
        }
    
         int op5=max(op1,max(op2,max(op3,op4)));
         finalAns.maxDiff=max(leftAns.maxDiff,max(rightAns.maxDiff,op5));
         finalAns.minElement=min(root->val,min(leftAns.minElement,rightAns.minElement));
         finalAns.maxElement=max(root->val,max(leftAns.maxElement,rightAns.maxElement));
         return  finalAns;     
    }
    int maxAncestorDiff(TreeNode* root) {
        Helper finalAns=solve(root);
        return finalAns.maxDiff;
    }
};