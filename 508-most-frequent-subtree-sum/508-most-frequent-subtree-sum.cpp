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
    int solve(TreeNode * root,unordered_map<int,int>&mp,int &maxfreq){
        if(root==NULL){
            return 0;
        }
        
        int leftans=solve(root->left,mp,maxfreq);
        int rightans=solve(root->right,mp,maxfreq);
        int totalSum=leftans + rightans + root->val;
        mp[totalSum]++;
        maxfreq=max(maxfreq,mp[totalSum]);
        return totalSum;        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxfreq=INT_MIN;
        int totalSum=solve(root,mp,maxfreq);
        vector<int>ans;
        for(auto i:mp){
            if(i.second==maxfreq)ans.push_back(i.first);
        }
        return ans;        
    }
};