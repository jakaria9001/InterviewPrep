/*

Problem Description

Given a linked list A, swap every two adjacent nodes and return its head.

NOTE: Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.



Problem Constraints
1 <= |A| <= 106



Input Format
The first and the only argument of input contains a pointer to the head of the given linked list.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

 A = 1 -> 2 -> 3 -> 4
Input 2:

 A = 7 -> 2 -> 1


Example Output
Output 1:

 2 -> 1 -> 4 -> 3
Output 2:

 2 -> 7 -> 1
 
 */

ListNode* Solution::swapPairs(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    
    ListNode *curr = head;
    
    while(curr && curr->next){
        
        swap(curr->val, curr->next->val);
        curr = curr->next->next;
        
    }
    return head;
}
