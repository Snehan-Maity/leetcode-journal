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
private:
    ListNode* reverseSLL(ListNode* head){
        ListNode* temp = head, *prev = NULL;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)    return;
        ListNode *slow = head,  *fast = head;
        fast = fast->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* rev = reverseSLL(second);
        
        ListNode* first = head;
        while(first->next){
            ListNode* temp1 = first->next;
            ListNode* temp2 = rev->next;
            
            first->next = rev;
            rev->next = temp1;

            first = temp1;
            rev = temp2;
        }
        first->next = rev;
        return;
    }
};