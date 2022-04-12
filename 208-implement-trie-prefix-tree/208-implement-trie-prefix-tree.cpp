class TrieNode{
  public:
  char data;
  TrieNode ** children;
  bool isTerminal;
  TrieNode(char x){
      data=x;
      children=new TrieNode * [26];
      for(int i=0;i<26;i++){
          children[i]=NULL;
      }
      isTerminal=false;
  }
    
};
class Trie {
public:
    TrieNode * root;
    Trie() {
        root=new TrieNode('\0');
    }
    void insertHelper(TrieNode * root,string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        
        int index=word[0]-'a';
        TrieNode * child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        
        insertHelper(child,word.substr(1));
    }
    void insert(string word) {
        return insertHelper(root,word);
    }
    
    bool searchHelper(TrieNode * root,string word) {
        if(word.size()==0){
            if(root->isTerminal==true){
                return true;
            }
            else{
                return false;
            }
        }
        int index=word[0]-'a';
        
        if(root->children[index]!=NULL){
           return searchHelper(root->children[index],word.substr(1));    
        }
        else{
            return false;
        }
    }
    bool search(string word){
        return searchHelper(root,word);
    }
    bool startsWithHelper(TrieNode * root,string prefix){
         if(prefix.size()==0){
           return true;
        }
        int index=prefix[0]-'a';
        
        if(root->children[index]!=NULL){
           return startsWithHelper(root->children[index],prefix.substr(1));    
        }
        else{
            return false;
        }
        
    }
    bool startsWith(string prefix) {
       return startsWithHelper(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */