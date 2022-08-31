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
    ListNode * revLinkedList(ListNode * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode * smallAns=revLinkedList(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallAns;
            
    }
    ListNode* plusOne(ListNode* head) {
      if(head==NULL){
          ListNode * newNode=new ListNode(1);
          return newNode;
      }   
      ListNode * revHead=revLinkedList(head);
      ListNode * temp=revHead;
      ListNode * prev=NULL;
      int carry=1;
      while(temp!=NULL && carry!=0){
          int d=temp->val + carry;
           carry=d/10;
           temp->val=d%10;
           prev=temp;
           cout<<temp->val<<endl;
           temp=temp->next; 
       }
        if(temp==NULL && carry!=0){
            ListNode * newNode=new ListNode(carry);
            prev->next=newNode;
            prev=newNode;
        }
        return revLinkedList(revHead);        
    }
};