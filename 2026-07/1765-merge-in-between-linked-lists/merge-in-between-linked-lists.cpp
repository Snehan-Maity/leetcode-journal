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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        int cnt=0;
        while(temp1->next){
            cnt++;
            if(cnt == a){
                ListNode* searchB = temp1->next;
                while(searchB && cnt != b){
                    searchB = searchB->next;
                    cnt++;
                }
                temp1->next = list2;
                while(temp1->next){
                     temp1 = temp1->next;
                     cout << temp1->val;
                }
                if(searchB->next)   temp1->next = searchB->next;
                break;
            }
            temp1 = temp1->next;
        }
        return list1;
    }
};