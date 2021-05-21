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
// https://leetcode.com/problems/reverse-linked-list-ii/submissions/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head && left==right) return head;
        
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *nodeBeforeLeft = &dummy;
        
        for(int i=1;i<left;i++){
            nodeBeforeLeft = nodeBeforeLeft->next; 
            // temp = temp->next;
        }
        // if(temp->next) temp= temp->next;
        ListNode *temp = nodeBeforeLeft->next, *cnext; 
        while(temp->next && left < right){
            cnext = temp->next;
            temp->next = cnext->next;
            cnext->next = nodeBeforeLeft->next;
            nodeBeforeLeft->next = cnext;
            left++;
        }
        return dummy.next;
    }
};
