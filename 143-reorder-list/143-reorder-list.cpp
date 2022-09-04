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
    ListNode * revLL(ListNode * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode * newhead=revLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode * midNode(ListNode * head){
        if(head==NULL || head->next==NULL){
           return head;
        }
        
        ListNode * slow=head;
        ListNode * fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
             return ;
            }
        ListNode * midpoint=midNode(head);
        ListNode * secondHead=midpoint->next;
        midpoint->next=NULL;
        ListNode * head2=revLL(secondHead);
        ListNode  * temp=head;
        ListNode * head1=temp->next;
        while(head1!=NULL || head2!=NULL){
             if(head2!=NULL){
                temp->next=head2;
                temp=temp->next;
                 head2=head2->next;
             }
            
             if(head1!=NULL){
                 temp->next=head1;
                 temp=temp->next;
                 head1=head1->next;
             }
            
        }
        temp->next=NULL;
        return;
    }
};