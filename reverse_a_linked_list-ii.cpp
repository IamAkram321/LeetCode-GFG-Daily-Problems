/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution { //T.C: O(N) and S.C: O(1)
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        //here we are reaching to portion from we need to reverse. Also leftPrev is 
        // used so that we can point to end later after completing reversing
        ListNode leftPrev=dummy;
        ListNode currNode = head;
        for(int i=0;i<left-1;i++){
            leftPrev = leftPrev.next;
            currNode = currNode.next;
        }

        ListNode subHead=currNode; //this is the head of newly reversed list
        ListNode prev=null;
        ListNode next=null;

        //this is same as reversing the linked list problem i
        for(int i=0;i<=right-left;i++){
            next=currNode.next;
            currNode.next=prev;
            prev=currNode;
            currNode=next;
        }
        //here we are joining left pieces
        leftPrev.next=prev;
        subHead.next=currNode;

        return dummy.next;
    }
}