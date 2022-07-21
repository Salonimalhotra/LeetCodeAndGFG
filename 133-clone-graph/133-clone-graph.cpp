/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include<bits/stdc++.h>
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        else if(node->neighbors.size()==0){
            Node * newnode=new Node(node->val);
            return newnode;
        }
       
        unordered_map<int,Node*>map;
        Node * newNode=new Node(node->val);
        map[node->val]=newNode;
        queue<Node*>q;
        q.push(node);
        while(q.size()!=0){
            Node * top=q.front();
            q.pop();
            Node * temp=map[top->val];
            for(Node * i: top->neighbors){
                if(map.find(i->val)!=map.end()){
                    temp->neighbors.push_back(map[i->val]);
                }
                else{
                    Node * x=new Node(i->val);
                    map[i->val]=x;
                    temp->neighbors.push_back(map[i->val]);
                    q.push(i);
                }
            }
        }
        
        return map[node->val];
    }
};