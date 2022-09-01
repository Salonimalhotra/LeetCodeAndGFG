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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if(m==0){
            return NULL;
        }
        if(n==0){
            return head;
        }
        
        ListNode * t1=head;
        ListNode * t2=head;
        int cnt1=1;
        int cnt2;
        while(t1!=NULL && t2!=NULL){
            cnt1=1;
            while(t1!=NULL && cnt1<m){
                t1=t1->next;
                cnt1++;
            }            
            cnt2=1;
            if(t1==NULL){
               break;
            }
            t2=t1->next;
            // t1->next=NULL;
            while(t2!=NULL && cnt2<=n){
                ListNode * temp=t2;
                t2=t2->next;
                delete temp;
                cnt2++;
            }
            
           
            t1->next=t2;
            t1=t2;            
        }
        
        if(t2==NULL && t1!=NULL){
            t1->next=NULL;
        }
        return head;
       
        
    }
};