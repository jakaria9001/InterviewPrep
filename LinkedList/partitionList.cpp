/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// https://www.interviewbit.com/problems/partition-list/
ListNode* Solution::partition(ListNode* A, int B) {

    if(!A || !A->next) return A;
    
    ListNode    *head = A, *nheadS = NULL, *ntailS=NULL,*nheadL = NULL, *ntailL=NULL ;
    
    while(head){
        if(head->val < B){
            if(!nheadS){
                nheadS = ntailS = head;
                head = head->next;
                ntailS->next = NULL;
            }else {
                ntailS->next = head;
                ntailS = head;
                head = head->next;
                ntailS->next = NULL;
            }
        }else {
            if(!nheadL){
                nheadL = ntailL = head;
                head = head->next;
                ntailL->next = NULL;
            }else {
                ntailL->next = head;
                ntailL = head;
                head = head->next;
                ntailL->next = NULL;
            }
        }
        
    }
    
    if(nheadS) ntailS->next = nheadL;
    else nheadS = nheadL;
    
    return nheadS;
    
    
}
