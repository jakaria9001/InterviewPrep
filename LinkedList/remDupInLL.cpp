/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */ 

 // Link : https://binarysearch.com/problems/Remove-Duplicates-in-Linked-List
LLNode* solve(LLNode* node) {
    LLNode *curr = node, *tmp = NULL;
    unordered_set<int> ss;

    while(curr){
        if(ss.find(curr->val)!=ss.end()){
            // remove this element
            tmp->next = curr->next;
            delete(curr);
        }else {
            ss.insert(curr->val);
            tmp = curr;
        }
        
        curr = tmp->next;
    }
    
    return node;
}
