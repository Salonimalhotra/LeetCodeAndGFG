/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<Node *>q;
        q.push(root);
        while(q.size()!=0){
            int s=q.size();
            vector<int>ans1;
            for(int i=0;i<s;i++){
                Node * topNode=q.front();
                q.pop();
                ans1.push_back(topNode->val);
                for(int i=0;i<topNode->children.size();i++){
                    if(topNode->children[i]!=NULL){
                        q.push(topNode->children[i]);
                    }
                }
                
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};