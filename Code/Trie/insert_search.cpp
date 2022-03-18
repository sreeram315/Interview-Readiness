void insert(struct TrieNode *root, string key) {
   int i = 0, n = key.length();
   while(i<n){
       if(!root->children[key[i]-'a'])
            root->children[key[i]-'a'] = getNewNode();
       root = root->children[key[i++]-'a'];
   }
   root->isLeaf = true;
}


bool search(struct TrieNode *root, string key) {
   int i = 0, n = key.length();
   while(i<n && root->children[key[i]-'a'])
       root = root->children[key[i++]-'a'];
   return (i==n) && (root->isLeaf);
}