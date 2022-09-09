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
    TreeNode * findNode(TreeNode * root,int start){
        if(root==NULL){
              return NULL;
        }
        
        if(root->val==start){
           return root;
        }
        
        TreeNode * findNodeleft=findNode(root->left,start);
        if(findNodeleft!=NULL){
            return findNodeleft;
        }
        else{
            return findNode(root->right,start);
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *,TreeNode *>parents;
        
        queue<TreeNode*>q1;
        q1.push(root);
        
        while(q1.size()!=0){
            TreeNode * topNode=q1.front();
            q1.pop();
            
            if(topNode->left!=NULL){
                q1.push(topNode->left);
                parents[topNode->left]=topNode;
            }
            
            if(topNode->right!=NULL){
                q1.push(topNode->right);
                parents[topNode->right]=topNode;
            }
        }
       
        unordered_map<TreeNode *,bool>vis;
        queue<TreeNode *>q;
        TreeNode * targetNode=findNode(root,start);    
        q.push(targetNode);
        vis[targetNode]=true;
        int mins=0;
        
        while(q.size()!=0){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                TreeNode * topNode=q.front();
                q.pop();
                if(parents.find(topNode)!=parents.end() && vis.find(parents[topNode])==vis.end()){
                    q.push(parents[topNode]);
                    vis[parents[topNode]]=true;
                }
                if(topNode->left!=NULL && vis.find(topNode->left)==vis.end()){
                      q.push(topNode->left);
                    vis[topNode->left]=true;                    
                }
                if(topNode->right!=NULL && vis.find(topNode->right)==vis.end()){
                      q.push(topNode->right);
                    vis[topNode->right]=true;        
                }
            
            }
            if(q.size()!=0)
            mins++;
        }
        return mins;      
        
    }
};