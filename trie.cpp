struct TrieNode {
    struct TrieNode *children[26];
    bool is_word_end;
};

struct TrieNode* getNode() {
    struct TrieNode *trie_node_ptr = new TrieNode;
    trie_node_ptr->is_word_end = false;
    for (int i = 0; i < 26; i++)
        trie_node_ptr->children[i] = NULL;
    return trie_node_ptr; 
}

void insert(struct TrieNode* root, string key) {
    struct TrieNode *ptr = root;
    for (int i = 0; i < key.size(); i++){
        int index = key[i] - 'a';
        if (ptr->children[index] == NULL)
            ptr->children[index] = getNode();
        ptr = ptr->children[index];
    }
    ptr->is_word_end = true;
}

bool search (struct TrieNode *root, string key) {
    struct TrieNode *ptr = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (ptr->children[index] == NULL)
            return false;
        ptr = ptr->children[index];
    }
    return (ptr->is_word_end);
}

int main() { 
    struct TrieNode *root;
    root = getNode();
    insert(root, "hello");
    cout << search(root, "hellb");
}
