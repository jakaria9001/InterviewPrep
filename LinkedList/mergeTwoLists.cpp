// Link: https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Merge Two lists : 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;
    
    if(A->val < B->val)
    {
        A->next = mergeTwoLists(A->next, B);
        return A;
    }
    else {
        B->next = mergeTwoLists(A, B->next);
        return B;
    }
    return NULL;
}
// iterative: 
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
class Solution {
public:
    ListNode* recurMerge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        
        if(a->val<b->val){
            a->next = recurMerge(a->next, b);
            return a;
        }else{
            b->next = recurMerge(a,b->next);
            return b;
        }
        return NULL;
        
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //  recursive: 
        return recurMerge(l1,l2);
        
        // iterative: 
        ListNode *t1 = l1, *t2 =l2;
        ListNode *nH = NULL, *nT = NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        while(t1 && t2){
            if(t1->val < t2->val){
                if(nH==NULL){
                    nH = nT = t1;
                }else{
                    nT->next = t1;
                    nT = t1;
                }
                t1 = t1->next;
                
            }else{
                if(nH==NULL){
                    nH = nT = t2;
                }else{
                    nT->next = t2;
                    nT = t2;
                }
                t2 = t2->next;
            }
        }
        if(t1 == NULL) nT->next = t2;
        if(t2 == NULL) nT->next = t1;
        return nH;
    }
};
*/
