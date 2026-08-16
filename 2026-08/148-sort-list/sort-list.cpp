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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(INT_MIN, head);
        while(temp && temp->next){
            if(temp->val <= temp->next->val)    temp = temp->next;
            else{
                ListNode* newNode = temp->next;
                temp->next = temp->next->next;
                ListNode* pre = dummy;
                while(pre->next->val <= newNode->val)   pre = pre->next;
                newNode->next = pre->next;
                pre->next = newNode;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};