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
        ListNode* prev = NULL, *temp = head;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st1, st2;
        ListNode* temp = l1;
        while(temp){
            st1.push(temp);
            temp = temp->next;
        }
        temp = l2;
        while(temp){
            st2.push(temp);
            temp = temp->next;
        }
        int carry=0;
        ListNode* dummy = new ListNode(-1);
        temp = dummy;
        while(!st1.empty() || !st2.empty()){
            int sum = carry;
            if(!st1.empty()){
                sum += st1.top()->val;
                st1.pop();
            }
            if(!st2.empty()){
                sum += st2.top()->val;
                st2.pop();
            }
            carry = sum/10;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }

        if(carry){
            temp->next = new ListNode(carry);
        }

        ListNode* newHead = reverseSLL(dummy->next);
        delete dummy;
        return newHead;
    }
};