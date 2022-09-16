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
    void helper(TreeNode * root,unordered_map<int,int>&mp,int &cnt){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            mp[root->val]++;
            int oddFreq=0;
            for(auto i:mp){
                if(i.second%2!=0){
                    oddFreq++;
                }
               
            }
            if(oddFreq<=1){
                // cout<<root->val;
                cnt++;
            }
            mp[root->val]--;
            if(mp[root->val]==0){
                mp.erase(root->val);
            }
            return;
        }
        
        mp[root->val]++;
        helper(root->left,mp,cnt);
        helper(root->right,mp,cnt);
        mp[root->val]--;
        if(mp[root->val]==0){
                mp.erase(root->val);
        }
        
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int cnt=0;
        unordered_map<int,int>mp;
        helper(root,mp,cnt);
        return cnt;        
    }
};