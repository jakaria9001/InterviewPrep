// Link: https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPal(ListNode* head){
        
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0, j = arr.size()-1;
        while(i<=j){
            if(arr[i]!=arr[j]) return false;
            i++,j--;
        }
        return true;
        
    }
    ListNode* middle(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *slow = NULL, *fast = head;
        while(fast && fast->next){
            if(!slow) slow = head;
            else slow = slow->next;
            
            fast = fast->next->next;
        }
        return slow;
    }
    int length(ListNode* head){
        ListNode* temp = head;
        int l = 0;
        while(temp){
            l++;
            temp = temp->next;
        }
        return l;
    }
    void printLL(ListNode* head){
        ListNode* temp = head;
        while(temp){
            cout<< temp->val<<" ";
            temp = temp->next;
        }
        
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        // one way of reversal: 
        ListNode *cur = head,*tHead, *temp;
        
        tHead = reverse(head->next);
        temp = tHead;
        while(temp&&temp->next) temp = temp->next;

        temp->next = cur;
        cur->next = NULL;
        // alternate way: 
        //         ListNode *tHead = reverse(head->next);
        //         head->next->next = head;
        //         head->next = NULL;
        //         return tHead;
        return tHead;
    }
    bool check(ListNode*& temp, ListNode* p){
        if(!p) {return true;}
        bool isPal = check(temp, p->next) ;
            if(temp->val != p->val) {return false;}
        temp = temp->next;
        return isPal;
    }
    bool isPalindrome(ListNode* head) {
        // O(n), O(n) solution: 
        // return isPal(head);
        
        // O(n), O(1) solution: 
        // steps: got to middle, reverse second half, compare the two halves.
        
//         if(!head || !head->next) return true;
//         if(!head->next->next) return (head->val==head->next->val);
        
//         ListNode *a = head, *b, *mid;
//         // find middle: 
//         mid = middle(head);
//         // cout<<mid->val;
//         // split according to lengths: 
//         // cout<<length(head);
//         if(length(head)%2==1){
            
//                 b = mid->next->next;
//                 mid->next = NULL;
           
//         }else{
                
//                 b = mid->next;
//                 mid->next = NULL;
//         }
//         // reverse second half: 
//         b = reverse(b);
//         printLL(b);
//         // compare the two halves:
//         while(a&&b){
//             if(a->val!=b->val) return false;
//             a = a->next, b = b->next;
//         }
//         return true;
        
            return check(head, head);
    }
};
