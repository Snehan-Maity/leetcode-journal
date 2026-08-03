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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt=1;
        while(temp && temp->next){
            cnt += 2;
            temp = temp->next->next;
        }
        if(!temp)   cnt -= 1;
        int seg = cnt/k;
        int rem = cnt%k;
        temp = head;
        ListNode* prev = NULL;
        vector<ListNode*> ans(k);
        for(int i=0; temp && i<k; i++, rem--){
            ans[i] =  temp;
            for(int j=0; j < seg+(rem>0); j++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;
        }
        return ans;
    }
};