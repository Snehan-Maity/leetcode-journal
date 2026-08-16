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
        if(!head || !head->next)    return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1, head);
        while(temp && temp->next){
            if(temp->val <= temp->next->val)    temp = temp->next;
            else{
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                ListNode* pre = dummy;
                while(pre->next->val < nextNode->val)  pre = pre->next;
                nextNode->next = pre->next;
                pre->next = nextNode;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};