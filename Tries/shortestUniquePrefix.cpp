struct Trie{
    int count;
    Trie* children[26];
};

Trie* getNode(){
    Trie* temp = new Trie;
    temp->count = 0;
    // for(int i=0;i<26;i++)
    //     temp->children[i] = NULL;
    memset(temp->children, NULL, sizeof(temp->children));
    return temp;
}

void insert(Trie* root, string s){
    Trie *temp = root;
    for(int i=0;i<s.length();i++){
        int idx = s[i]-'a';
        if(temp->children[idx] == NULL)
            temp->children[idx] = getNode();

        temp->children[idx]->count++;
        temp = temp->children[idx];
    }
}


void findp(Trie* root, string wsf, vector<string>&ans){ // when order doesnt matter ( preorder prefixes)
    if(!root) return;
    if(root->count == 1){
        ans.push_back(wsf);
        return;
    } 
    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            char curr = i+'a';
            findp(root->children[i], wsf+curr, ans);
        }
    }
}


void findpp(Trie* root, string s, vector<string>&ans){
    
    Trie* temp = root;
    string prefix = "";
    for(int i=0;i<s.length();i++){
        prefix += s[i];
        if(temp->children[s[i]-'a'] && temp->children[s[i]-'a']->count == 1) break;
        temp = temp->children[s[i]-'a'];
    }
    ans.push_back(prefix);
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    Trie* root = getNode();
    
    for(string s: A)
        insert(root, s);
    
    for(string s: A)
        findpp(root, s, ans);
    // findp(root, "", ans);
    
    // reverse(ans.begin(),ans.end());
    return ans;
}
