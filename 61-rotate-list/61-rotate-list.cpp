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
    int lengthLL(ListNode * head){
        if(head==NULL){
            return 0;
        }
        return 1+lengthLL(head->next);
    }
    ListNode* getTail(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
           return head;
        }
        else{
            return getTail(head->next);
        }
    }
    ListNode* rotateRight(ListNode* head, int k) {
         if(head==NULL || k==0 || head->next==NULL){
             return head;
         }
        int len=lengthLL(head);
        int cnt=0;
        ListNode* temp=head;
        if(k>len){
            k=k%len;
        }
        while(temp!=NULL && cnt<len-k-1){
            temp=temp->next;
            cnt++;
        }
       
        if(temp!=NULL && temp->next!=NULL && cnt==len-k-1){
             ListNode* newTail=getTail(temp->next);
            newTail->next=head;
            head=temp->next;
            temp->next=NULL;
            return head;
        }
        return head;
    }
};