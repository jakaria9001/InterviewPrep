// Link : https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node *newHead=NULL, *temp = head, *ntemp=NULL;
        
        unordered_map<Node*, Node*> mpp;
        // create the clone of original elements : 
        while(temp){
            Node *nn = new Node(temp->val);
            if(newHead==NULL){
                newHead = nn;
                ntemp = nn;
            }else {
                ntemp->next = nn;
                ntemp = nn;
            }
            temp = temp->next;            
        }
        // update the map : 
        temp = head, ntemp = newHead;
        while(temp){
            mpp[temp] = ntemp;
            temp = temp->next;
            ntemp = ntemp->next;
        }
        // update the new random pointers :
        temp = head, ntemp = newHead;
        while(temp){
            ntemp->random = mpp[temp->random];
            temp = temp->next;
            ntemp = ntemp->next;
        }
        return newHead;
     // O(n) - O(n)   
        
    }
};
