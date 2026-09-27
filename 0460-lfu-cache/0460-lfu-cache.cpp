class LFUCache {
public:
    int capacity;
    int minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> keyInfo;

    // frequency -> keys, ordered from least recently used
    unordered_map<int, list<int>> freqList;

    // key -> iterator in its frequency list
    unordered_map<int, list<int>::iterator> position;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFrequency(int key) {
        int freq = keyInfo[key].second;

        freqList[freq].erase(position[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);

            if (minFreq == freq)
                minFreq++;
        }

        freq++;

        keyInfo[key].second = freq;

        freqList[freq].push_front(key);
        position[key] = freqList[freq].begin();
    }

    int get(int key) {
        if (!keyInfo.count(key))
            return -1;

        int value = keyInfo[key].first;

        updateFrequency(key);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // Key already exists
        if (keyInfo.count(key)) {
            keyInfo[key].first = value;
            updateFrequency(key);
            return;
        }

        // Cache full → remove LFU
        if (keyInfo.size() == capacity) {
            int removeKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyInfo.erase(removeKey);
            position.erase(removeKey);
        }

        // Insert new key
        keyInfo[key] = {value, 1};

        freqList[1].push_front(key);
        position[key] = freqList[1].begin();

        minFreq = 1;
    }
};