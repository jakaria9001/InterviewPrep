/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 UndirectedGraphNode* cg(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& hash) {
     if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cg(x,hash) );
           }
       }
    
       
       return hash[node];
 }

UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *node) {
    
    
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    // hash.clear();
    return cg(node, hash);
}
