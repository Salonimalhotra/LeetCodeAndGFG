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

void helper(TreeNode * root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    
    helper(root->left,arr);
    arr.push_back(root->val);
    helper(root->right,arr);
    return;
}
class BSTIterator {
public:
    vector<int>arr;
    int i;
    int size=0;
    BSTIterator(TreeNode* root) {
        helper(root,arr);   
        i=0;
        size=arr.size();
    }
    
    int next() {
        if(i==size){
            return -1;
        }
        else{
            i++;
            return arr[i-1];            
        }
    }
    
    bool hasNext() {
        if(i<size){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */