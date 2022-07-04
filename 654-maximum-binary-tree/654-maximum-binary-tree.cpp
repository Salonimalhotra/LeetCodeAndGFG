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
#include<algorithm>
#include<bits/stdc++.h>
class Solution {
public:    
    TreeNode * helper(vector<int>& nums,int start,int end){
        if(start>end){
            return NULL;
        }
        else if(start==end){
            TreeNode * newNode=new TreeNode(nums[start]);
            return newNode;
        }
        int maxvalueIndex=-1;
        for(int i=start;i<=end;i++){
            if( maxvalueIndex==-1 || nums[i]>nums[maxvalueIndex]){
                maxvalueIndex=i;
            }
        }
        
        TreeNode * root=new TreeNode(nums[maxvalueIndex]);
        root->left=helper(nums,start,maxvalueIndex-1);
        root->right=helper(nums,maxvalueIndex+1,end);
        return root;        
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        return helper(nums,0,nums.size()-1);        
        
    }
};