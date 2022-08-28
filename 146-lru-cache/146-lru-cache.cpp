class Node{
    public:
    int key;
    int value;
    Node * prev;
    Node * next;
    
    Node(int k,int v){
        this->key=k;
        this->value=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    Node * head;
    Node * tail;
    int capacity;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
        
    }
    
    void deleteNode(Node * delnode){
        Node * delprev=delnode->prev;
        Node * delnext=delnode->next;
        
        delprev->next=delnext;
        delnext->prev=delprev;
        
    }
    
    void addNode(Node * newNode){
    Node * temp = head -> next;
    newNode -> next = temp;
    newNode -> prev = head;
    head -> next = newNode;
    temp -> prev = newNode;
        return;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
           Node * temp=mp[key];
           int res=mp[key]->value;
           mp.erase(key);
           deleteNode(temp);
           // Node * newnode=new Node(key,res);
           addNode(temp);
           mp[key]=head->next;
           return res;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node * delnode=mp[key];
            mp.erase(key);
            deleteNode(delnode);
        }
        
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        Node * newNode=new Node(key,value);
        addNode(newNode);
        mp[key]=head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */