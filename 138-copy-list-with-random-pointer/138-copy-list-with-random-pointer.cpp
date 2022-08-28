/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //first step is initially creating copy nodes and connection itr ka next with copy ka next
        Node * itr=head;
        Node * front=head;
        
        while(itr!=NULL){
            front=itr->next;
            Node * copy=new Node(itr->val);
            itr->next=copy;
            copy->next=front;
            
            itr=front;
        }
        
        // second step is to link random nodes of copy  nodes with random copy nodes just like random nodes have been                    connected
        
        itr=head;
        while(itr!=NULL){
            if(itr->random!=NULL){
                itr->next->random=itr->random->next;
             
            }
               itr=itr->next->next;
        }
        
        //third and final step is to basically disconnect our original linked list with copy linked list 
        
        itr=head;
        Node * dummyNode=new Node(0);
        Node * copyNode =dummyNode;
        
        while(itr!=NULL){
            front =itr->next->next;
            copyNode->next=itr->next;
            itr->next=front;
            copyNode=copyNode->next;
            itr=itr->next;
        }
        return dummyNode->next;
    }
};