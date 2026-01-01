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
T
class Solution {
  public: //T.C: O(n+m) and S.C: O(1)
    Node* intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return NULL;

        Node* p1 = head1;
        Node* p2 = head2;

        while (p1 != p2) {
            p1 = (p1 == NULL) ? head2 : p1->next;
            p2 = (p2 == NULL) ? head1 : p2->next;
        }

        return p1;
    }
};
