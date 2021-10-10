// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// Code:
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* temp = dummy;
        int current;
        
        while(temp->next and temp->next->next){
            
            if(temp->next->val == temp->next->next->val){
                current = temp->next->val;
                while(temp->next and temp->next->val == current){
                    temp->next = temp->next->next;
                }            
            }else {
                temp = temp->next;
            }
        }
        
        return dummy->next;
    }
};
