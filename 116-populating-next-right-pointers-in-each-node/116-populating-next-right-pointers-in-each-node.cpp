/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
             return root;
        }
        queue<Node *>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=0){
            Node * topNode=q.front();
            q.pop();
            if(topNode==NULL && q.size()==0){
                break;
            }
            else if(topNode==NULL && q.size()!=0){
                q.push(NULL);
                continue;
            }
            
            topNode->next=q.front();
            
            if(topNode->left!=NULL){
                q.push(topNode->left);
            }
            
            if(topNode->right!=NULL){
                q.push(topNode->right);
            }            
            
        }
        return root;
    }
};