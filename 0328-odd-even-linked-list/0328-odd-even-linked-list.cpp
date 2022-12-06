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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * oddHead=NULL;
        ListNode * evenHead=NULL;
        ListNode * oddTail=NULL;
        ListNode * evenTail=NULL;
        ListNode * temp=head;
        int cnt=1;
        while(temp!=NULL){
             if(cnt%2==0){
                 if(evenHead==NULL){
                     evenHead=temp;
                     evenTail=temp;
                 }
                 else{
                     evenTail->next=temp;
                     evenTail=temp;
                 }
             }
            else{
                if(oddHead==NULL){
                     oddHead=temp;
                     oddTail=temp;
                 }
                 else{
                     oddTail->next=temp;
                     oddTail=temp;
                 }
            }
            temp=temp->next;
            cnt++;
        }
        
        oddTail->next=evenHead;
        evenTail->next=NULL;
        return oddHead;        
    }
};