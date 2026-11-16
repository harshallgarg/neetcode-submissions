class LRUCache {
public:

    unordered_map<int, pair<int, list<int> :: iterator>> ump; // {key, {value,itr}}
    list<int> list1; // to store keys and track the LRU
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        
        if(ump.find(key)==ump.end())
        return -1;

        list1.erase(ump[key].second);
        list1.push_front(key);
        ump[key].second = list1.begin();
        return ump[key].first;
    }
    
    void put(int key, int value) {
        int size = list1.size();

        if(ump.find(key)!=ump.end()){
            list1.erase(ump[key].second);
            list1.push_front(key);
            ump[key].first = value;
            ump[key].second = list1.begin();
        }
        else{
            if(size==capacity){
                ump.erase(list1.back());
                list1.pop_back();
            }
            
            list1.push_front(key);
            ump[key] = {value,list1.begin()};
        }
    }
};
