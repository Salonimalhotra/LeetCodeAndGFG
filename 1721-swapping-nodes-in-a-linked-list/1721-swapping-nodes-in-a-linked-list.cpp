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
        int cnt=0;
        ListNode * temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        // cout<<cnt<<endl;
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt=1;
        ListNode * temp1=head;
        while(temp1!=NULL && cnt<k){
            temp1=temp1->next;
            cnt++;
            
        }
        int n=lengthLL(head);
        int x=n-k+1;
         cnt=1;
        ListNode * temp2=head;
        while(temp2!=NULL && cnt<x){
            temp2=temp2->next;
            cnt++;
            
        }
        
        int y=temp1->val;
        temp1->val=temp2->val;
        temp2->val=y;
        
        return head;
        
    }
};