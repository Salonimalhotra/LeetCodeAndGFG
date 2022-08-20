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
    ListNode * midpointLL(ListNode * head1){
         ListNode * slow=head1;
         ListNode * fast=head1->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
       stack<int>st;       
        ListNode * mid=midpointLL(head);
        ListNode * temp=mid->next;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        
        ListNode * head1=head;
        int maxSum=INT_MIN;
        while(head1!=mid->next){
            maxSum=max(maxSum,head1->val + st.top());
            // cout<<head1->val + st.top()<<endl;
            st.pop();
            head1=head1->next;
        }
        return maxSum;      
        
    }
};