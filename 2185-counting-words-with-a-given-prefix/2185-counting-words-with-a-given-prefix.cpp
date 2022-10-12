class TrieNode
{
    public:
        char data;
    TrieNode **children;
    bool isTerminal;
    int cntPrefix;
    TrieNode(char d)
    {
        this->data = d;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        cntPrefix = 1;
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
        else
        {
            child->cntPrefix++;
        }

        insertWord(word.substr(1), child);
    }

    void insert(string word)
    {
        insertWord(word, root);
    }
    int cntWords(TrieNode *root, string pref)
    {
        if (pref.size() == 0) return root->cntPrefix;

        TrieNode *child = root->getChild(pref[0]);
        if (child == NULL)
        {
            return 0;
        }

        return cntWords(child,pref.substr(1));
    }
    int cntWords(string pref)
    {
        return cntWords(root, pref);
    }
};
class Solution
{
    public:
        int prefixCount(vector<string> &words, string pref) {
          Trie trie;
          for(int i=0;i<words.size();i++){
            trie.insert(words[i]);
          }
          return trie.cntWords(pref);
        }
};