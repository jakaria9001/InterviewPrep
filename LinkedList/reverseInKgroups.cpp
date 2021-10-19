/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A) return NULL;
    ListNode *prev = NULL, *curr = A, *next;
    
    int count = 0;
    while(curr!= NULL && count<B){
                count++;
                curr =  curr->next;
    }
    if(count == B){
                curr=A;
                count = 0;
        while(curr and count<B){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        A->next = reverseList(next, B);
    return prev;
}
return A;
}
