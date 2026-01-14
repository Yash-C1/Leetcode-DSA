class KeyNode {
public:
    int key;
    int val;
    int freq;
    KeyNode* next;
    KeyNode* prev;

    KeyNode(int _key, int _val, int _freq) {
        key = _key;
        val = _val;
        freq = _freq;
        next = nullptr;
        prev = nullptr;
    }
};

class LFUCache {
private:
    unordered_map<int,KeyNode*> keyNodeMap;
    unordered_map<int,pair<KeyNode*,KeyNode*>> FreqListMap;
    int current_size;
    int capacity;
    int min_freq;

    // To add a node in FreqListMap in the list for that freq key.
    void add_node(pair<KeyNode*,KeyNode*> p, KeyNode* node){
        KeyNode* tail = p.second;
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }

    // To remove a node in FreqListMap in the list for that freq key.
    void remove_node(KeyNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // To check in FreqListMap if the list for that freq key is empty after removing a node.
    bool check_empty(pair<KeyNode*,KeyNode*> p){
        return p.first->next == p.second;
    }

    // To add a new freq key along with pair of head and tail nodes for that freq in FreqListMap.
    void add_new_freq(unordered_map<int,pair<KeyNode*,KeyNode*>> &FreqListMap, int freq){
        KeyNode* head = new KeyNode(-1,-1,-1);
        KeyNode* tail = new KeyNode(-1,-1,-1);
        head->next = tail;
        tail->prev = head;
        FreqListMap[freq] = {head,tail};
    }

public:
    LFUCache(int capacity) {
        current_size = 0;
        this->capacity = capacity;
        min_freq = 0;
    }
    
    int get(int key) {
        int ans = -1;
        if(keyNodeMap.find(key)==keyNodeMap.end()) return ans;
        else{
            ans = keyNodeMap[key]->val;
            int freq = keyNodeMap[key]->freq;
            // remove_node(keyNodeMap[key]);
            // if(check_empty(FreqListMap[freq])){
            //     if(freq==min_freq) min_freq++;
            //     FreqListMap.erase(freq);
            // }
            put(key, ans);
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(keyNodeMap.find(key)==keyNodeMap.end()) {
            // this key does not exist already
            if(current_size>=capacity){
                KeyNode* node = FreqListMap[min_freq].first->next;
                remove_node(node);
                keyNodeMap.erase(node->key);
                delete node;
                current_size--;
            }

            KeyNode* new_node = new KeyNode(key,value,1);
            keyNodeMap[key] = new_node;

            if(FreqListMap.find(1)==FreqListMap.end()) add_new_freq(FreqListMap,1);
            add_node(FreqListMap[1], new_node);
            current_size++;
            min_freq = 1;
        }else{
            // this key exists already.
            keyNodeMap[key]->val = value;
            int freq = keyNodeMap[key]->freq;
            keyNodeMap[key]->freq++;
            remove_node(keyNodeMap[key]);
            if(check_empty(FreqListMap[freq])){
                if(freq==min_freq) min_freq++;
                FreqListMap.erase(freq);
            }

            freq++;

            if(FreqListMap.find(freq)==FreqListMap.end()) add_new_freq(FreqListMap,freq);
            add_node(FreqListMap[freq], keyNodeMap[key]);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




 
