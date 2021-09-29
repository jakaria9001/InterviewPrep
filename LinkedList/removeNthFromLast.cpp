/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int getLength(ListNode* head){
    int l = 0;
    ListNode* temp = head;
    while(temp!=NULL) {
        l++;
        temp = temp->next;
    }
    return l;
}

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int l = getLength(A);
    if(B>=l) return A->next;
    
    ListNode *slow = A, *fast = A;
    for(int i=0;i<B;i++){
        fast = fast->next;
    }
    if(!fast) return A->next;
    
    while(fast->next) fast = fast->next, slow = slow->next;
    slow->next = slow->next->next;
    
    // else temp->next = NULL;
    return A;
}
