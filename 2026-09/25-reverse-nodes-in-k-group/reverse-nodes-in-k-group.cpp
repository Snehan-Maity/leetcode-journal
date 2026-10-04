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
    ListNode* rev(ListNode* temp, int k){
        int cnt=0;
        ListNode* prev = NULL;
        while(cnt < k){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            cnt++;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1)  return head;
        ListNode* temp=head, *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGrp = dummy;
        while(temp){
            ListNode* start = temp;
            int cnt=0;
            while(temp && cnt<k){
                cnt++;
                temp=temp->next;
            }
            if(cnt < k)     break;
            ListNode* newHead = rev(start, k);
            prevGrp->next = newHead;
            start->next = temp;
            prevGrp = start;
        }
        return dummy->next;
    }
};