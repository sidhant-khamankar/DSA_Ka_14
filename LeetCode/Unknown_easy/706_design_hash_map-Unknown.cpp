/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start

class MyHashMap
{
public:
    // My solution tried chaining with class, wrong answer

    // LeadCoding by Fraz solution O1 time put, get, remove On space
    // On time if collisions
    vector<list<pair<int, int>>> m;
    int siz;
    MyHashMap()
    {
        siz = 1e6 + 1; //size of hash table can be less as collisions are handled by chaining using doubly linked list
        m.resize(siz);
    }

    int hash(int key)
    {
        return key % siz;
    }

    list<pair<int, int>>::iterator search(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = m[i].begin();
        while (it != m[i].end())
        {
            if (it->first == key)
                return it;
        }

        return it;
    }

    void put(int key, int value)
    {
        int i = hash(key);
        remove(key);
        m[i].push_back({key, value});
    }

    int get(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        if (it == m[i].end())
            return -1;
        else
            return it->second;
    }

    void remove(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        if (it != m[i].end())
            m[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
