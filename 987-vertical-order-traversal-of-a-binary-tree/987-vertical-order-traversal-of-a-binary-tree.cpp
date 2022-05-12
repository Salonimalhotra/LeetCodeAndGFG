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
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
class Solution {
public:
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
         return ans;
        }
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,vector<int>>>map;
        pair<TreeNode*,pair<int,int>>p=make_pair(root,make_pair(0,0));
        q.push(p);
        while(q.size()!=0){
           pair<TreeNode*,pair<int,int>>topNode=q.front();
            q.pop();
           TreeNode * frontNode=topNode.first;
           int vertical=topNode.second.first;
           int level=topNode.second.second;
           
          map[vertical][level].push_back(frontNode->val);
          if(frontNode->left!=NULL){
             q.push(make_pair(frontNode->left,make_pair(vertical-1,level+1)));
          }
          if(frontNode->right!=NULL){
              q.push(make_pair(frontNode->right,make_pair(vertical+1,level+1)));
          }
        }
        
        // for(auto i:map){
        //     for(auto j:i.second){
        //        // sort(j.second.begin(),j.second.end());
        //         for(auto k:j.second){
        //             sort(k.begin(),k.end());
        //         }
        //     }
        // }
        for(auto i:map){
            vector<int>ans1;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second){
                    ans1.push_back(k);
                }
            }
            ans.push_back(ans1);
        }
        
        
        
        return ans;
    }
};