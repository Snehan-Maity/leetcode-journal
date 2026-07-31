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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(temp){
            if(temp->next && temp->val == temp->next->val){
            ListNode* front = temp->next;
                while(temp && temp->val == front->val)   temp = temp->next;
            }
            else{
                prev->next = temp;
                prev = prev->next;
                temp = temp->next;
                prev->next = nullptr;
            }
        }
        if(temp)    prev->next = temp;
        return dummy->next;
    }
};