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
    int GCD(int a, int b){
        while(a>0 && b>0){
            if(a>b)     a %= b;
            else    b %= a;
        }
        if(a == 0)  return b;
        else    return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* temp = head;
        while(temp->next){
            ListNode* front = temp->next;
            int gcd = GCD(temp->val, front->val);
            ListNode* newNode = new ListNode(gcd, front);
            temp->next = newNode;
            temp = temp->next->next;
        }
        return head;
    }
};