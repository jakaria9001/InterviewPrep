// link : https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = 0, sum = 0;
    ListNode *head = NULL, *tail = NULL ;
    
    while(A || B || carry){
        
        sum = (A?A->val:0) + (B?B->val:0) + carry ;
        carry = sum/10;
        sum = sum%10;
        
        ListNode *tmp = new ListNode(sum);
        
        if(head==NULL) { head = tmp; tail = tmp;}
        else { tail->next = tmp; tail = tmp;}
        
        if(A) A = A->next; 
        if(B) B = B->next;
    }
    
    return head;
}
