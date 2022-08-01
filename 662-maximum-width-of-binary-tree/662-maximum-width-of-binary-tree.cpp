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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode * ,int>>q;
        q.push(make_pair(root,0));
        int maxWidth=0;
        
        while(q.size()!=0){
            
            int minIndex=q.front().second;
            int n=q.size();
            int f=0;
            int l=0;
            
            for(int i=0;i<n;i++){
                TreeNode * topNode=q.front().first;
                int indx=q.front().second;
                q.pop();
                
                long curr=indx-minIndex;
                
                if(i==0){
                    f=curr;
                }
                else if(i==n-1){
                    l=curr;
                }
                
                if(topNode->left!=NULL){
                    q.push(make_pair(topNode->left,2 * curr +1));
                    
                }
                if(topNode->right!=NULL){
                    q.push(make_pair(topNode->right,2 * curr+2));
                }
                
                
            }
            maxWidth=max(maxWidth,l-f+1);
        }
        return maxWidth;
    }
};