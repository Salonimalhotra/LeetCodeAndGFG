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
    pair<ListNode *,ListNode *> revLinkedlist(ListNode * head){
        if(head==NULL || head->next==NULL){
              pair<ListNode *,ListNode *>Ans;
              Ans.first=head;
              Ans.second=head;
              return Ans;
        }
        
          pair<ListNode *,ListNode *> smallAns=revLinkedlist(head->next);
          smallAns.second->next=head;
          head->next=NULL;
          smallAns.second=head;
          return smallAns;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp=head;
        int cnt=1;
        while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
        }
        if(temp==NULL){
            //  pair<ListNode *,ListNode *> first_k_reverse=revLinkedlist(head);
            // return first_k_reverse.first;
            return head;
        }
        ListNode * secondhead=temp->next;
        temp->next=NULL;
        pair<ListNode *,ListNode *> first_k_reverse=revLinkedlist(head);
        ListNode * nextAns=reverseKGroup(secondhead,k);
        first_k_reverse.second->next=nextAns;
        return first_k_reverse.first;
    }
};