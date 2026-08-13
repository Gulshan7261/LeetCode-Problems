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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* second = head;

        // maintain gap of n b/w first and second 
        while(n>0 && second!=NULL){
            second = second->next ;
            n--;
        }
        
        if(second == NULL){
            if(n>0){
                return head;
            }
            // del at head
            if(n==0){
                ListNode* temp = head;
                head = head->next;
                temp->next = NULL;
                return head;

            }
        }

        ListNode* first = head;
        ListNode* prev = NULL;
        while(second!=NULL){
            prev = first;
            first = first->next;
            second=second->next;

        }

        // now you are the nth node from the end
        prev->next = first->next;
        first->next =NULL;

        return head;

    }
};