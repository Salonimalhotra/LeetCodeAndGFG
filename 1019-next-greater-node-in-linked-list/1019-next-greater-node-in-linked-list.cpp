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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode * temp=head;
        while(temp!=NULL){
            ListNode * temp1=temp->next;
            while(temp1!=NULL){
                if(temp1->val>temp->val){
                    break;
                }
                else{
                    temp1=temp1->next;
                }
            }
            if(temp1!=NULL){
                ans.push_back(temp1->val);
            }
            else{
                ans.push_back(0);
            }
            temp=temp->next;
        }
        return ans;
    }
};