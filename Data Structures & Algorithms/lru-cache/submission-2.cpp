class Node{
    public:
        Node* next;
        Node* prev;
        int value;
        int key;
        Node(int key_, int value_){
            next = nullptr;
            prev = nullptr;
            value = value_;
            key = key_;
        }
};

class LRUCache {
private:
    int capacity;
    map<int, Node*> mp;
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void call(int key){
        Node* tmp = mp[key];
        if(mp[key] == head && head->next){
            head = head->next;
            head->prev = nullptr;
            
            tmp->prev = tail;
            tmp->next = nullptr;
            tail->next = tmp;
            tail = tmp;
        } else {
            if(mp[key] != tail){
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                
                tmp->prev = tail;
                tmp->next = nullptr;
                tail->next = tmp;
                tail = tmp;
            }
        }
    }
    
    int get(int key) {
       if(mp.count(key)){
            call(key);
            return mp[key]->value;
       }
       return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->value = value;
            call(key);
        } else {
            Node* n = new Node(key, value);
            cout << mp.size() << " " << capacity << endl;
            if(mp.size() == capacity){
                Node* temp = head;
                head = head->next;
                if(head){
                    head->prev = nullptr;
                } // TH head = tail
                else {
                    tail = nullptr;
                }
                mp.erase(temp->key);
                delete temp;
            }  
            if(head == nullptr && tail == nullptr){
                    head = n;
                    tail = n;
            } else {
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
            mp[key] = tail;
        }
    }
};
