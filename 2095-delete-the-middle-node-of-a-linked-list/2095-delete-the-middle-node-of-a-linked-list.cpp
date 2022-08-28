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
    pair<ListNode * ,ListNode * > midpointLL(ListNode * head){
        ListNode * prev=NULL;
        ListNode * slow=head;
        ListNode * fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        pair<ListNode * ,ListNode * >ans;
        ans.first=prev;
        ans.second=slow;
        return ans;
        
    }
    ListNode* deleteMiddle(ListNode* head) {
          if(head==NULL){
              return NULL;
          }   
        
         else if(head->next==NULL){
             delete head;
             return NULL;
         }
        
        // else if(head->next->next==NULL){
        //     ListNode * temp=head;
        //     head=head->next;
        //     delete temp;
        //     return head;
        // }
        
        pair<ListNode * ,ListNode * >ans=midpointLL(head);
        ListNode * prev=ans.first;
        ListNode * slow=ans.second;
        ListNode * temp=slow;
        prev->next=slow->next;
        delete slow;
        return head;
        
    }
};