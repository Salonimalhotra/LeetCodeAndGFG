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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * temp1=list1;
        ListNode * temp2=list1;        
        int cnt=1;
        
        while(cnt<a && temp1!=NULL){
            temp1=temp1->next;
            cnt++;
        }
        
        cnt=0;
        
        while(cnt<=b && temp2!=NULL){
            temp2=temp2->next;
            cnt++;
        }
        // cout<<temp2->val<<endl;
        ListNode * secondTail=list2;
        
        while(secondTail->next!=NULL){
            secondTail=secondTail->next;
        }
        
        temp1->next=list2;
        secondTail->next=temp2;
        return list1;
        
    }
};