/*
    T.C: O(N+M)
    S.C: O(M)
*/
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* curr = head;
        ListNode* prev = dummy;
        
        while (curr) {
            if (st.count(curr->val)) {
                // Remove this node
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
