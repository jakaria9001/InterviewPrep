struct TrieNode{
    bool isEnd;
    TrieNode *children[26];
};
TrieNode* getNode(){
    TrieNode *newNode = new TrieNode;
    newNode->isEnd = false;
    for(int i=0;i<26;i++)
        newNode->children[i] = NULL;
        
    return newNode;
}
void insert(TrieNode *root, string str){
    TrieNode *temp = root;
    for(int i=0;i<str.length();i++){
        if(temp->children[str[i]-'a'] == NULL){
           TrieNode *nn = getNode();
           temp->children[str[i]-'a'] = nn;
        }
        temp = temp->children[str[i]-'a'];
    }
    temp->isEnd = true;
}
bool search(TrieNode* root, string str){
    TrieNode *temp = root;
    
    for(int i=0;i<str.length();i++){
        if(temp->children[str[i]-'a']==NULL)
            return false;
        temp = temp->children[str[i]-'a'];
    }
    
    return (temp!=NULL && temp->isEnd);
    // return true;
    // return false;
}
vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    vector<int> ans;
    TrieNode* root = getNode();
    for(string s: A)
        insert(root, s);
    for(string s: B)
        ans.push_back(search(root, s));

    return ans;
}
