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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        priority_queue<pair<int, ListNode*>> pq;

        for(auto ll:lists) {

            if(ll != NULL){
             pair<int,ListNode*> p;
             p.first = -ll->val;
             p.second = ll;
             pq.push(p);

            }

          
        }

        ListNode* dummyRoot = new ListNode(INT_MAX);
        ListNode* end = dummyRoot;
        while(!pq.empty()){

            pair<int, ListNode*> poppedList = pq.top();
            pq.pop();
            end->next = poppedList.second;
            end = end->next;

            if(end-> next !=NULL)
            {
                poppedList.first = -end->next->val;
                poppedList.second =end->next;
                pq.push(poppedList);
            }

        }
        return dummyRoot->next;
        
    }
};