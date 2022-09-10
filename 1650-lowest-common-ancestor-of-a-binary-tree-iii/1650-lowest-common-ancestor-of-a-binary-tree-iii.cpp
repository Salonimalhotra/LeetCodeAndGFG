/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node *>path1;
        Node * temp1=p;
        while(temp1!=NULL){
            path1.push_back(temp1);
            temp1=temp1->parent;
        }
        Node * temp2=q;
        vector<Node *>path2;
        while(temp2!=NULL){
            path2.push_back(temp2);
            temp2=temp2->parent;
        }
        
        int i=0;
        int j=0;
        while(i<path1.size() && j<path2.size()){
            if(path1[i]->val==path2[j]->val){
                return path1[i];
            }
            else{
                if(path1.size()-i<=path2.size()-j){
                    j++;
                }
                else{
                    i++;
                }
            }
        }
        return NULL;
    }
};