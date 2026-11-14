class TimeMap {
public:

    unordered_map<string, vector<pair<string,int>> > ump;
    // key, {value, timestamp}

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        
        vector<pair<string,int>> &v = ump[key];
        int low=0;
        int high = v.size() - 1;

        int index = v.size();

        while(low<=high){
            int mid = low + (high-low)/2;

            if(v[mid].second==timestamp)
            return v[mid].first;

            if(v[mid].second<timestamp){
                index = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        
        if(index == v.size())
        return "";

        return v[index].first;
    }
};
