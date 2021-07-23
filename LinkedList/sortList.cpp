// Link: https://leetcode.com/problems/sort-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Steps: check if there are at least two nodes, find middle element, use two pointers to split the list into two parts, 
//        recursively sort the two lists, merge the two lists, and return the new head after merging. 
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        
        if(a->val < b->val){
            a->next = merge(a->next, b);
            return a;
        }else {
            b->next = merge(a,b->next);
            return b;
        }
        // return NULL;
    }
    ListNode* middle(ListNode* head){
        if(!head ||!head->next) return head;
        ListNode *slow=NULL,*fast = head;
        
        while(fast && fast->next){
            if(slow==NULL) slow=head;
            else slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        // find middle and sort the two halves accordingly
        
        if(!head ||!head->next) return head;
        
        ListNode *a = head, *b, *mid;
        mid = middle(head);
        b= mid->next;
        mid->next = NULL;
        
        a = sortList(a);
        b = sortList(b);
        ListNode* mergedHead= merge(a,b);
        return mergedHead;
        
    }
};
