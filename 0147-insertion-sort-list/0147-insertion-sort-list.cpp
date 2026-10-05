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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;

        }
        ListNode* temp = head->next;
        ListNode* sortedTail = head;

        while(temp != nullptr){
            if(temp->val >= sortedTail->val){
                sortedTail = temp;
                temp = temp->next;
                continue;
            }
            sortedTail->next = temp->next;

            ListNode* prev = nullptr;
            ListNode* t1 = head;

            while (t1 != sortedTail->next) {
                if(t1->val >= temp->val){
                    break;
                }
                prev = t1;
                t1 = t1->next;
            }
            if(prev == nullptr){
                temp->next = head;
                head = temp;
            }
            else {
                temp->next = prev->next;
                prev->next = temp;
            }
            temp = sortedTail->next;
        }
        return head;

        
    }
};