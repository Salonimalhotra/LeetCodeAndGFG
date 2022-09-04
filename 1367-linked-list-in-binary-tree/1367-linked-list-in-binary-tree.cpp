/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void findNode(TreeNode * root,int x,vector<TreeNode*>&v){
        if(root==NULL){
          return;
        }
        if(root->val==x){
            v.push_back(root);
           
        }
        findNode(root->left,x,v);
        findNode(root->right,x,v);
        return;
        
    }
    bool helper(TreeNode * x,ListNode * head){
         if(head==NULL){
             return true;
         }
        if(x==NULL && head!=NULL){
           return false;
        }
        
        if(x->val==head->val){
            bool leftAns=helper(x->left,head->next);
            if(leftAns==true){
                return true;
            }
            bool rightAns=helper(x->right,head->next);
            if(rightAns==true){
                return true;
            }
            else{
                return false;
            }
        }
        
       return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode *>v;
        findNode(root,head->val,v);
        for(int i=0;i<v.size();i++){
            bool check=helper(v[i],head);
            if(check==true){
                return true;
            }
        }
        return false;
        
    }
};