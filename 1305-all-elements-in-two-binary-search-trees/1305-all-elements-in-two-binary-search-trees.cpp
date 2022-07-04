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
    void helper(TreeNode * root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        helper(root1,ans1);
        vector<int>ans2;
        helper(root2,ans2);
        int i=0;
        int j=0;
        vector<int>finalAns;
        while(i<ans1.size() && j<ans2.size()){
            if(ans1[i]<ans2[j]){
                finalAns.push_back(ans1[i]);
                i++;
            }
            else if(ans1[i]>ans2[j]){
                finalAns.push_back(ans2[j]);
                j++;
            }
            else{
                finalAns.push_back(ans1[i]);
                i++;
            }
        }
        while(i<ans1.size()){
                finalAns.push_back(ans1[i]);
                i++;
        }
        
        while(j<ans2.size()){            
                finalAns.push_back(ans2[j]);
                j++;
        }
        return finalAns;
    }
};