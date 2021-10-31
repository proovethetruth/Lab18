#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <utility>

template <class T>
class Hashmap {
private:
	std::vector<std::list<std::pair<std::string, int>>> keys;

public:
    Hashmap() {
        keys.resize(100);
    }

    parent_hash populpock;

    Hashmap(parent_hash peredal) {
        keys.resize(100);
        populpock = peredal;
    }

    void insert(const std::string& key, int value) {
        int h = populpock.hash();
        keys[h].push_back(std::make_pair(key, value));
		return;
    }

    void erase(const std::string& key) {
        int h = populpock.hash();
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
        int h = populpock.hash();
        for (auto tmp : keys[h]) {
            if (key.compare(tmp.first) == 0) {
                return { tmp.second, true };
            }
        }
        return { 0, false };
    }
};

class parent_hash {
public:
    parent_hash() {};
    virtual const int hash() { return 0; }
};

class hash1 : public parent_hash {
public:
    hash1() {};
    virtual const int hash() { return 1; }
};

class hash2 : public parent_hash {
public:
    hash2() {};
    virtual const int hash() { return 2; }
};


#endif // !HASH_H
