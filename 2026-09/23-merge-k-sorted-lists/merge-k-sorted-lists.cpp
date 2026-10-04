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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1? l1:l2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return nullptr;
        while(lists.size() > 1){
            vector<ListNode*> temp;
            for(auto i=0; i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2;
                if(i+1 < lists.size())  l2 = lists[i+1];
                else    l2 = nullptr;
                temp.push_back(merge2Lists(l1, l2));
            }
            lists = temp;
        }
        return lists[0];
    }
};