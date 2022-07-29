class TrieNode{
  public:
   char data;
   TrieNode ** children;
   bool isTerminal;
  
    TrieNode(char d){
        this->data=d;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
           children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {
   TrieNode * root;
    public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insertHelper(string word,TrieNode * root){        
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }        
        TrieNode * child;
        int index=word[0]-'a';
        if(root->children[index]==NULL){
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        else{
            child=root->children[index];
        }
        
        insertHelper(word.substr(1),child);
        
    }
    void insert(string word) {
        insertHelper(word,root);        
    }
    
    bool searchHelper(string word,TrieNode * root){
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
           return searchHelper(word.substr(1),root->children[index]);      
       }
        else{
            return false;
        }        
          
    }
    
    bool search(string word) {
        return searchHelper(word,root);
    }
    
    bool startsWithHelper(string prefix,TrieNode * root){
        if(prefix.size()==0){
            return true;
        }
        
          int index=prefix[0]-'a';
       if(root->children[index]!=NULL){
           return startsWithHelper(prefix.substr(1),root->children[index]);      
       }
        else{
            return false;
        }    
        
        
    }
    bool startsWith(string prefix) {
         return startsWithHelper(prefix,root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */