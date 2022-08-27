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
    ListNode * reverseLL(ListNode * head){
        if(head==NULL || head->next==NULL){
             return head;
        }
        
        ListNode * smallAns=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallAns;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        
        //brute Force Approach:-
        // vector<int>ans;
        // ListNode * temp=head;
        // while(temp!=NULL){
        //     ListNode * temp1=temp->next;
        //     while(temp1!=NULL){
        //         if(temp1->val>temp->val){
        //             break;
        //         }
        //         else{
        //             temp1=temp1->next;
        //         }
        //     }
        //     if(temp1!=NULL){
        //         ans.push_back(temp1->val);
        //     }
        //     else{
        //         ans.push_back(0);
        //     }
        //     temp=temp->next;
        // }
        // return ans;
        
        vector<int>ans;
        if(head==NULL){
            return ans;
        }
        ListNode * newHead=reverseLL(head);        
        ListNode * temp=newHead;        
        
        stack<int>st;
        while(temp!=NULL){
            if(st.size()==0){
                ans.push_back(0);
            }
            else{
                while(st.size()!=0 && st.top()<=temp->val){
                    st.pop();
                }
                if(st.size()!=0){
                    ans.push_back(st.top());
                }
                else{
                     ans.push_back(0); 
                }
            }
            st.push(temp->val);
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
};