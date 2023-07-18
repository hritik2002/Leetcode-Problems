class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;
            node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int capacity;
    vector<node*> map;
    int size;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
        size = 0;
        this->map.resize(10001, NULL);
    }
    
    void deleteNode(node* curNode){
        node* prev = curNode->prev;
        node* next = curNode->next;

        prev->next = next;
        next->prev = prev;
    }
    
    void addNode(node* curNode){
        curNode->next = head->next;
        curNode->prev = head;
        curNode->next->prev = curNode;
        head->next = curNode;
    }
    
    int get(int key) {
        if(this->map[key] == NULL) return -1;
        
        node* curNode = this->map[key];
        int result = curNode->val;
        this->map[key] = NULL;
        deleteNode(curNode);
        addNode(curNode);
        this->map[key] = head->next;
        
        return result;
    }
    
    void put(int key, int value) {
        if(this->map[key]){
            node* curNode = this->map[key];
            this->map[key] = NULL;
            deleteNode(curNode);
            size--;
        }
        if(size == capacity){
            this->map[tail->prev->key] = NULL;
            size--;
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        this->map[key] = head->next;
        size++;
    }
};