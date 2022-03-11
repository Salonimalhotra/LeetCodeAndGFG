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
    void inorderTraversal(TreeNode * root,vector<int>&ans){
        if(root==NULL){
        return;
        }
        inorderTraversal(root->left,ans);
        ans.push_back(root->val);
        inorderTraversal(root->right,ans);
        return;
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorderTraversal(root,ans);
        bool check=false;
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]==k){
                check=true;
                break;
                
            }
            else if(ans[i]+ans[j]<k){
                 i++;
            }
            else if(ans[i]+ans[j]>k){
                j--;
            }
            
        }
        return check;
        
    }
};