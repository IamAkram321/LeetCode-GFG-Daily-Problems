/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public: //T.C: O(n) and S.C: O(k) where k = number of lists
    Node* merge(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        Node* result;
        if(a->data < b->data){
            result = a;
            result->bottom = merge(a->bottom,b);
        }else{
            result = b;
            result->bottom = merge(a,b->bottom);
        }
        result->next = nullptr;
        return result;
    }
    Node *flatten(Node *root) {
        
    //   if(!root) return nullptr;
        
    //   vector<int> arr;
    //   Node* temp = root;
       
    //   while(temp){
    //       Node* down = temp;
    //       while(down){
    //           arr.push_back(down->data);
    //           down = down->bottom;
    //       }
    //       temp = temp->next;
    //   }
    //   sort(arr.begin(),arr.end());
    //   Node* head = new Node(arr[0]);
    //   Node* current = head;
    //   for(int i=1;i<arr.size();i++){
    //       current->bottom = new Node(arr[i]);
    //       current = current->bottom;
    //   }
    //   return head;
    
        if(!root || !root->next){
            return root;
        }
        root->next = flatten(root->next);
        root = merge(root,root->next);
        return root;
    }
};