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
public: //T.C: O(N) and S.C: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode* curr = head;
       while(curr && curr->next){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
       }
       return head;
    }
};