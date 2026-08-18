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
         ListNode* Mid(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast->next != nullptr && fast->next->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        ListNode* mergeSortList(ListNode *p1,ListNode *p2){
            if(p1 == nullptr || p2 == nullptr){
                return (p1 == nullptr) ? p2 : p1;
            }
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;

            while(p1 != nullptr && p2 != nullptr){
                if(p1->val < p2->val){
                    curr->next = p1;
                    p1 = p1->next;
                }else {
                    curr->next = p2;
                    p2 =p2->next;
                }
                curr = curr->next;
            }
            // if(p1 != nullptr || p2 != nullptr){
            if(p1 != nullptr){
                // curr->next = (p1 != nullptr) ? p1 :p2;
                curr->next = p1;
            }
            else {
                curr->next = p2;
            }

            // return ans->next;
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
        }
       ///****************

       ListNode* sortList(ListNode* head) {

         if(head == nullptr or head->next == nullptr) return head;

          ListNode* mid = Mid(head);
          //start 
        ListNode* newhead = mid->next;

        // break the linked list 
        mid->next = nullptr;

        //sort left half
         ListNode* left_half = sortList(head);

         // sort right half
         ListNode* right_half = sortList(newhead);

        // merge sorted halves
         return mergeSortList(left_half, right_half);

    }
};

       