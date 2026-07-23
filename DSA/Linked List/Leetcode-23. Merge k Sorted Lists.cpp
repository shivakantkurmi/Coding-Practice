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
    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(l1||l2){
            int v=0;
            if(l1 && l2){
                if (l1->val>l2->val){
                    v=(l2->val);
                    l2=l2->next;
                }
                else{
                    v=l1->val;
                    l1=l1->next;
                }
            }
            else if(l1){
                v=l1->val;
                l1=l1->next;

            }
            else{
                v=l2->val;
                l2=l2->next;
            }
             dummy->next=new ListNode(v);
             dummy=dummy->next;

        }
        return head->next;
        delete(dummy);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int interval = 1;
        while(interval < lists.size()){
            for(int i=0;i+interval<lists.size();i+=2*interval){
                lists[i] = mergeTwo(lists[i], lists[i+interval]);
            }
            interval*=2;
        }

        return lists[0];
    }
};
