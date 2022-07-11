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

class Solution {
public:
     ListNode * reverseLL( ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
         ListNode* newhead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    
    int length(ListNode * head){
        if(head==NULL){
            return 0;
        }
        else{
            return 1+length(head->next);
        }
    }
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        else if(head->next==NULL){
            return head;
        }
        else if(k==0){
            return head;
        }
        else if(k>length(head)){
           return head;
        }
        else if(k==length(head)){
             return reverseLL(head);
        }
         ListNode * curr=head;
        int count=0;
        while(curr!=NULL && count<k-1){
            curr=curr->next;
            count++;
        }
         ListNode * temp=curr->next;
        curr->next=NULL;
         ListNode * newhead=reverseLL(head);
         ListNode* newtail=reverseKGroup(temp,k);
        head->next=newtail;
        return newhead;
    }
};