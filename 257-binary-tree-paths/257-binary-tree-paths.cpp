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
#include<vector>
#include<string>
class Solution {
public:
    void helper(TreeNode * root,vector<string>&ans,string start){
        if(root==NULL){
            return;
        }
        else if(root->left==NULL && root->right==NULL){
            if(start.size()!=0){
                start.append("->");
                start.append(to_string(root->val));
                ans.push_back(start);
                return ;
            }
            else{
                start.append(to_string(root->val));
                ans.push_back(start);
                return ;
            }
        }
        
        if(start.size()!=0){
                start.append("->");
                start.append(to_string(root->val));
            }
            else{
                start.append(to_string(root->val));
            }
        helper(root->left,ans,start);
        helper(root->right,ans,start);
        start.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans;
        string start="";
         helper(root,ans,start);
        return ans;
         
    }
};