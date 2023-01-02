// class for doubly linkedlist
class node{
    public:
        int key;
        int value;
        node* prev;
        node* next;
    
        node(int key, int value) {
            this->key = key;
            this->value = value;
        }
};

class LRUCache {
public:
    map<int, node*> map;
    int capacity;
    node* head;
    node* tail;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        }
        
        node* currNode = map[key];
        int res = currNode->value;
        // delete the node and add that node in the front
        deleteFromBack(currNode);
        addToFront(currNode);
        // update the map
        map[key] = currNode;
        
        return res;
    }
    
    // add to the front node sequence
    void addToFront(node* tmpNode) {
        this->head->next->prev = tmpNode;
        tmpNode->next = this->head->next;
        this->head->next = tmpNode;
        tmpNode->prev = this->head;
    }
    // delete the given node
    void deleteFromBack(node* currNode) {
        node* tmp = currNode->prev;
        tmp->next = currNode->next;
        currNode->next->prev = tmp;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            // delete the node with old value
            deleteFromBack(map[key]);
            map.erase(key);
        }
        if(map.size() == this->capacity) {
            // delete the least recent used node
            map.erase(this->tail->prev->key);
            deleteFromBack(this->tail->prev);
        }
        
        // add a node with the new value
        addToFront(new node(key, value));
        // update the map
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */