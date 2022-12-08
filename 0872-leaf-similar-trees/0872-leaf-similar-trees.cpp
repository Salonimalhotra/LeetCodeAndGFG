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
    void getAllLeaves(TreeNode * root1,vector<int>&arr){
      if(root1==NULL){
         return;
      }
      if(root1->left==NULL && root1->right==NULL){
        arr.push_back(root1->val);
        return;
      }
      getAllLeaves(root1->left,arr);
      getAllLeaves(root1->right,arr);
      return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;
        getAllLeaves(root1,arr1);
        getAllLeaves(root2,arr2);
        int i=0;
        int j=0;
        if(arr1.size()!=arr2.size()){
          return false;
        }
        while(i<arr1.size() && j<arr2.size()){
          if(arr1[i]!=arr2[j]){
            return false;
          }
          i++;
          j++;
        }
      return true;
    }
};