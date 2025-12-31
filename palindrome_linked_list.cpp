/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public://T.C: O(n) and S.C: O(1)
    Node* reverseLL(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        
        if(!head || !head->next) return true;
        
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* secondHalf = reverseLL(slow);
        Node* firstHalf = head;
        
        while(secondHalf){
            if(firstHalf->data != secondHalf->data) return false;
            secondHalf = secondHalf->next;
            firstHalf  = firstHalf->next;
        }
        return true;
    }
};