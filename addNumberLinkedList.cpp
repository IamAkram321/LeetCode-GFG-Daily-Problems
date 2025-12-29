/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public: //T.C: O(n + m) and S.C: O(1)
  
    Node* reverse(Node* head){
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
    
    Node* removeLeadingZeros(Node* head){
        while(head && head->data==0 && head->next){
            head = head->next;
        }
        return head;
    }
  
    Node* addTwoLists(Node* head1, Node* head2) {
        
        removeLeadingZeros(head1);
        removeLeadingZeros(head2);
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        int carry = 0;
        
        while (head1 || head2 || carry) {
            int v1 = head1 ? head1->data : 0;
            int v2 = head2 ? head2->data : 0;
            
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            
            curr->next = new Node(digit);
            curr = curr->next;
            
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }
        Node* result = reverse(dummy->next);
        return removeLeadingZeros(result);
    }
};
