#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <utility>

template <typename T>
class Hashmap {
private:
	std::vector<std::list<std::pair<std::string, int>>> keys;
	size_t max_col = 3;
	size_t max_cap = 100;

public:
    Hashmap() {
        keys.resize(max_cap);
    }

    int hash(const std::string& str)
    {
        unsigned long hash = 5381;
        int c = 0;
        for (int i = 0; i < str.length(); c = str[i], i++)
            hash = ((hash << 5) + hash) + c + (753817 * str[i]);

        return abs((int)hash % max_cap);
    }

    void insert(const std::string& key, int value) {
        int h = hash(key);
        keys[h].push_back(std::make_pair(key, value));
		return;
    }

    void erase(const std::string& key) {
        int h = hash(key);
        for (auto tmp : keys[h]) {
            if (key.compare(tmp.first) == 0) {
                keys[h].remove(tmp);
                return;
            }
        }
    }

    friend std::ostream& operator << (std::ostream& os, Hashmap& arr) {
        std::cout << "\n";
        for (int i = 0; i < (int)arr.keys.size(); i++) {
            os << " " << i << ": ";
            for (auto tmp : arr.keys[i])
                os << tmp.first << " " << tmp.second << "   ";
            os << std::endl;
        }
        return os;
    }

    std::pair<int, bool> find(const std::string& key) {
        int h = hash(key);
        for (auto tmp : keys[h]) {
            if (key.compare(tmp.first) == 0) {
                return { tmp.second, true };
            }
        }
        return { 0, false };
    }
};
#endif // !HASH_H
