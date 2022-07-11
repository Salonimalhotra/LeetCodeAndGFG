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
class Pair{
    public:
    ListNode * head;
    ListNode * tail;
};
class Solution {
public:
    Pair rev(ListNode * head){
        if(head==NULL){
            Pair ans;
            ans.head=NULL;
            ans.tail=NULL;
            return ans;
        }
        else if(head->next==NULL){
            Pair ans;
            ans.head=head;
            ans.tail=head;
            return ans;
        }
           Pair semiAns=rev(head->next);
           semiAns.tail->next=head;
           head->next=NULL;
           Pair finalAns;
           finalAns.head=semiAns.head;
           finalAns.tail=head;
           return finalAns;        
    }
    int len(ListNode * head){
        if(head==NULL){
            return 0;
        }
        return 1+len(head->next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        else if(k>len(head)){
            return head;
        }
        else if(k==len(head)){
            Pair ans=rev(head);
            return ans.head;
        }
        int cnt=0;
        ListNode * temp=head;
        while(temp!=NULL && cnt<k-1){
            temp=temp->next;
            cnt++;
        }
        ListNode * firstTail=temp;
        ListNode * secondHead=firstTail->next;
        firstTail->next=NULL;
        ListNode * semiAns=reverseKGroup(secondHead,k);
        Pair revAns=rev(head);
        revAns.tail->next=semiAns;
        return revAns.head;
    }
};