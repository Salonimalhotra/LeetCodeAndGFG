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
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;            
        }
        stack<TreeNode *>s1;
        TreeNode * curr=root;
        while(true){
            if(curr!=NULL){
           s1.push(curr);
            curr=curr->left;
        }
       else{
           if(s1.size()==0){
               break;
           }
           TreeNode * topNode=s1.top();
           s1.pop();
           ans.push_back(topNode->val);
           curr=topNode->right;
           
       }
        }
        return ans;
    }
};