/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    int carry = 0;
    ListNode *head1 = A, *head2 = B;
    
    ListNode *result = NULL, *tail = NULL;
    
    while(head1 && head2){
        carry += head1->val + head2->val;
        ListNode *nn = new ListNode(carry%10);
        carry/=10;
        if(result==NULL){ result = tail= nn; }
        else { tail->next = nn; tail = nn; }
        
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1){
        carry += head1->val;
        ListNode *nn = new ListNode(carry%10);
        carry/=10;
        if(result==NULL){ result = tail= nn; }
        else { tail->next = nn; tail = nn; }
    
        head1 = head1->next;
    }
    while(head2){
        carry += head2->val;
        ListNode *nn = new ListNode(carry%10);
        carry/=10;
        if(result==NULL){ result = tail= nn;}
        else { tail->next = nn; tail = nn; }
    
        head2 = head2->next;
    }
    if(carry){
        ListNode *nn = new ListNode(carry%10);
        carry/=10;
        if(result==NULL){ result = tail= nn; }
        else { tail->next = nn; tail = nn; }
    }
    return result;
}
