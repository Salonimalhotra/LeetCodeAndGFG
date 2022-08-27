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
    ListNode* swapPairs(ListNode* head) {
        ListNode * temp1=head;
        if(head==NULL || head->next==NULL){
        return head;
        }
        
        ListNode * temp2=temp1->next; 
        ListNode * prev=NULL;
       while(temp1!=NULL && temp2!=NULL){
            if(temp1==head){
                head=temp2;
            }
            if(prev!=NULL){
                prev->next=temp2;
            }
                temp1->next=temp2->next;
                temp2->next=temp1;
                prev=temp1;
                
                temp1=temp1->next;
                if(temp1!=NULL){
                    temp2=temp1->next;
                }
                else{
                    temp2=NULL;
                }
            
       }
        return head;
    }
};