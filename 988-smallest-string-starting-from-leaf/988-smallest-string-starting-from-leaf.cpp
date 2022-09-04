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
    void solve(TreeNode * root,string &smallAns,string &helper){
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            helper.push_back(root->val + 'a');
            string x=helper;
            reverse(x.begin(),x.end());
            if(smallAns==""){
                smallAns=x;
            }
            else if(smallAns>x){
                smallAns=x;
            }
            helper.pop_back();
            return;
        }
        
        helper.push_back(root->val + 'a');
        solve(root->left,smallAns,helper);
        solve(root->right,smallAns,helper);
        helper.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string smallAns="";
        string helper="";
        solve(root,smallAns,helper);
        return smallAns;
    }
};