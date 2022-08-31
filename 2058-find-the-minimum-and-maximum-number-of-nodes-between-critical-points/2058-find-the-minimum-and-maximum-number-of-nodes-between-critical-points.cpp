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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,0);
        int min_p=INT_MAX;
        int max_p=INT_MIN;
        map<int,int>mp;
        ListNode * prev=NULL;
        
        ListNode * temp=head;
        int pos=1;
        while(temp!=NULL){
            if(prev==NULL){
                prev=temp;
                temp=temp->next;
                pos++;
            }
            else if(temp->next==NULL){
                break;
            }
            else if(temp->val<prev->val && temp->val<temp->next->val || temp->val>prev->val && temp->val>temp->next->val){
                 if(mp.size()==0){
                     mp[pos]++;
                     prev=temp;
                     temp=temp->next;
                     pos++;
                 }
//                 else if(mp.size()==1){
//                     map<int, int>::iterator itr=mp.begin();
//                      min_p=min(min_p,pos-itr->first);
//                      max_p=max(max_p,pos-itr->first);
//                      mp[pos]++;
//                      prev=temp;
//                      temp=temp->next;
//                      pos++;
                  
//                 }
                else{
                    map<int,int>::iterator itr=mp.begin();
                    max_p=max(max_p,pos-itr->first);
                    itr=mp.end();
                    itr--;
                    min_p=min(min_p,pos-itr->first);                  
                     mp[pos]++;
                     prev=temp;
                     temp=temp->next;
                     pos++;
                }
            }
            else{
                     prev=temp;
                     temp=temp->next;
                     pos++;
            }
        }
//         for(auto i:mp){
//             cout<<"printing map"<<i.first<<endl;
//         }
        
        if(min_p==INT_MAX){
            ans[0]=-1;
            ans[1]=-1;
        }
        else{
            ans[0]=min_p;
            ans[1]=max_p;
        }
        return ans;
        
    }
};