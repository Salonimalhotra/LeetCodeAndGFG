class TrieNode
{
    public:
        char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char d)
    {
        this->data = d;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }

    TrieNode* getChild(char d)
    {
        return children[d-'a'];
    }
};
class Trie
{
    TrieNode * root;
    public:
        Trie()
        {
            root = new TrieNode('\0');
        }

    void insertWord(string word, TrieNode *root)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        TrieNode *child = root->getChild(word[0]);
        if (child == NULL)
        {
            root->children[word[0] - 'a'] = new TrieNode(word[0]);
            child = root->children[word[0] - 'a'];
        }

        insertWord(word.substr(1), child);
    }
    void insert(string word)
    {
        insertWord(word, root);
    }

    bool searchWord(string word, TrieNode *root)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true) return true;
            return false;
        }

        TrieNode *child = root->getChild(word[0]);
        if (child == NULL) return false;
        return searchWord(word.substr(1), child);
    }
    bool search(string word)
    {
        return searchWord(word, root);
    }
    bool startsWithWord(string prefix, TrieNode *root)
    {
        if (prefix.size() == 0) return true;

        TrieNode *child = root->getChild(prefix[0]);
        if (child == NULL) return false;
        return startsWithWord(prefix.substr(1), child);
    }
    bool startsWith(string prefix)
    {
        return startsWithWord(prefix, root);
    }
};

/**
 *Your Trie object will be instantiated and called as such:
 *Trie* obj = new Trie();
 *obj->insert(word);
 *bool param_2 = obj->search(word);
 *bool param_3 = obj->startsWith(prefix);
 */