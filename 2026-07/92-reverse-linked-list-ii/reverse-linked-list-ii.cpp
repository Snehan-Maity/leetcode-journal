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
        if(!head || !head->next)    return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev=temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)    return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt=1;
        while(cnt < left){
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        ListNode* start = prev;
        ListNode* firstNode = temp;
        while(cnt < right){
            temp = temp->next;
            cnt++;
        }
        ListNode* end = temp->next;
        temp->next = nullptr;
        ListNode* newHead = reverseSLL(firstNode);

        if(start)   start->next = newHead;
        else    head = newHead;
        firstNode->next = end;
        return head;
    }
};