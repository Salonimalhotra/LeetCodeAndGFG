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
    void flatten(TreeNode* root) {
        // stack ka approach :- time complexity:-O(N) && space complexity:-O(N)
        if(root==NULL) return;
       stack<TreeNode *>st;
        st.push(root);
        while(st.size()!=0){
            TreeNode * curr=st.top();
            st.pop();
            
            if(curr->right!=NULL)st.push(curr->right);
            if(curr->left!=NULL)st.push(curr->left);
            
            if(st.size()!=0)curr->right=st.top();
            curr->left=NULL;
        }
        return;
    }
};