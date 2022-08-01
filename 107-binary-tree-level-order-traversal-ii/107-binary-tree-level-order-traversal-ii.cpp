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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       stack<vector<int>>ans;
        if(root==NULL){
            vector<vector<int>>a;
            return a;
        }
        vector<int>smallAns;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=0){
            TreeNode * frontNode=q.front();
            q.pop();
            if(frontNode==NULL){
                if(q.size()==0){
                    ans.push(smallAns);
                    break;
                }
                ans.push(smallAns);
                smallAns.clear();       
                q.push(NULL);
            }
            else{
                 smallAns.push_back(frontNode->val);
                if(frontNode->left!=NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    q.push(frontNode->right);
                }
                                
            }      
            
        }
        vector<vector<int>>finalAns;
        while(ans.size()!=0){
            finalAns.push_back(ans.top());
            ans.pop();
        }
        return finalAns;
    }
};