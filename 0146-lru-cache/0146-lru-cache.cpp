class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int val) {
        key = k;
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*> mpp;
    int capacity;
    int size;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        mpp[key]->prev->next = mpp[key]->next;
        mpp[key]->next->prev = mpp[key]->prev;
        Node* temp = tail->prev;
        temp->next = mpp[key];
        mpp[key]->next = tail;
        mpp[key]->prev = temp;
        tail->prev = mpp[key];
        return mpp[key]->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->value = value;
            int t = get(key);
            return;
        }
        Node* new_node = new Node(key,value);
        Node* temp = tail->prev;
        tail->prev = new_node;
        new_node->next = tail;
        temp->next = new_node;
        new_node->prev = temp;

        mpp[key] = new_node;

        if(size < capacity) size++;
        else{
            Node* d = head->next;
            head->next = d->next;
            d->next->prev = head;
            mpp.erase(d->key);
            delete d;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */