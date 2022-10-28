/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* insertionSortList(ListNode *head)
        {
            if (head == NULL || head->next == NULL) return head;
            ListNode *newhead = head;
            ListNode *head2 = head->next;
            head->next = NULL;
            ListNode *temp1 = head2;

            while (temp1 != NULL)
            {
                ListNode *frontNode = temp1;
                temp1 = temp1->next;
                frontNode->next = NULL;

                if (frontNode->val < newhead->val)
                {
                    frontNode->next = newhead;
                    newhead = frontNode;
                }
                else
                {
                    ListNode *temp2 = newhead;
                    while (temp2->next != NULL)
                    {
                        if (temp2->next->val < frontNode->val)
                        {

                            temp2 = temp2->next;
                        }
                        else
                        {
                            frontNode->next = temp2->next;
                            temp2->next = frontNode;
                            break;
                        }
                    }
                    if (temp2->next == NULL)
                    {
                        temp2->next = frontNode;
                    }
                }
            }
           return newhead;
        }
};