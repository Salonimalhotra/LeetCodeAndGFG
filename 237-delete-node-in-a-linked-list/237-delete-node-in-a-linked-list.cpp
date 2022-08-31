/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL){
            return;
        }
        ListNode * curr=node;
        while(curr->next!=NULL && curr->next->next!=NULL){
            curr->val=curr->next->val;
            curr=curr->next;
        }
        
        if(curr->next->next==NULL){
            curr->val=curr->next->val;
            ListNode * temp=curr->next;
            curr->next=NULL;
            delete temp;
            
        }
        
        return;
    }
};