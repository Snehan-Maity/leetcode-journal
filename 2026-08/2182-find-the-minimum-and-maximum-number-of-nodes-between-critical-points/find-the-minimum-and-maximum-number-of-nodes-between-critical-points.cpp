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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev=head, *curr=head->next, *next=head->next->next;
        int prevCnt=0, cnt=1, nextCnt=0;
        vector<int> ans = {INT_MAX, -1};
        while(next){
            if((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)){
                if(nextCnt == 0){
                    prevCnt = cnt;
                    nextCnt = cnt;
                }
                else{
                    ans[0] = min(ans[0], cnt-prevCnt);
                    prevCnt = cnt;
                }
            }
            prev = curr;
            curr = next;
            next = next->next;
            cnt++;
        }
        if(nextCnt != 0 && prevCnt != nextCnt)  ans[1] = prevCnt - nextCnt;
        else    ans[0] = -1;
        return ans;
    }
};