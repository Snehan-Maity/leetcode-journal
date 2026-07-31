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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)    return head;

        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);

        ListNode* temp1 = dummy1;
        ListNode* temp2 = dummy2;

        ListNode* mover = head;
        while(mover){
            cout << mover->val << " ";
            if(mover->val < x){
                temp1->next = mover;
                temp1 = temp1->next;
                // temp1->next = nullptr;
            }
            else{
                temp2->next = mover;
                temp2 = temp2->next;
                // temp2->next = nullptr;
            }
            mover = mover->next;
        }
        temp2->next = nullptr;
        temp1->next = dummy2->next;
        return dummy1->next;
    }
};