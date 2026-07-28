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
        ListNode* temp = head;
        if(head == NULL)    return head;
        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        cnt = cnt-n+1;
        if(cnt == 1){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        int cnt2=0;
        temp = head;
        ListNode* prev=NULL;
        while(temp){
            cnt2++;
            if(cnt2 == cnt){
                prev->next = temp->next;
                delete temp;
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};