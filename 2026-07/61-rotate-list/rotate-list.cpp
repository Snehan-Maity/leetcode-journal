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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)    return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        k %= cnt;
        if(k == 0)  return head;
        for(int i=0; i<k; i++)  fast=fast->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        temp = slow;
        slow = slow->next;
        temp->next = nullptr;
        fast->next = head;
        return slow;
    }
};