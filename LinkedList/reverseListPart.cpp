// Link: https://leetcode.com/problems/reverse-linked-list-ii/


ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(!A || B==C) return A; 
    
    ListNode dum(0);
    dum.next = A;
    
    ListNode *cur = &dum;
    
    
    for(int i=1;i<B;i++){
        cur=cur->next;
    }
    
    ListNode *temp = cur->next, *cnext;
    while(temp->next && B < C){
        cnext = temp->next;
        temp->next = cnext->next;
        cnext->next = cur->next;
        cur->next = cnext;
        B++;
    }
    // temp->next = pre;
    return dum.next;
    
}
