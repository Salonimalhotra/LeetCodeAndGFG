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
    ListNode * reverse(ListNode * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode * smallAns=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallAns;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * revhead1=reverse(l1);
        ListNode * revhead2=reverse(l2);
        
        ListNode * newHead=NULL;
        ListNode * newTail=NULL;
        
        ListNode * temp1=revhead1;
        ListNode * temp2=revhead2;
        int sum=0;
        int carry=0;
        
        while(temp1!=NULL || temp2!=NULL || sum!=0 || carry!=0){
            if(temp1!=NULL){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            sum=sum%10;            
            
            if(sum>=0){
                ListNode * newNode=new ListNode(sum);
                if(newHead==NULL){
                    newHead=newNode;
                    newTail=newNode;
                }
                else{
                    newTail->next=newNode;
                    newTail=newNode;
                }
                sum=0;
            }
        }
        newTail->next=NULL;
        return reverse(newHead);
    }
};