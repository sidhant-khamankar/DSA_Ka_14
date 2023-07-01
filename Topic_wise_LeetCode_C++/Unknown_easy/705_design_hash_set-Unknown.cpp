/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet
{

    // My solution using vector On search time
    //but ordered hashset uses bst internally logn search time
    // unordered hashset uses hash table which is array
    // On add search remove On space

    //Leadcoding by Fraz solution
    // with basic hash function and chaining
    // O1 time add remove search On space

public:
    vector<list<int>> m;
    int siz;

    MyHashSet()
    {
        siz = 1e6 + 1; //size of hash table can be less as collisions are handled by chaining using doubly linked list
        m.resize(siz);
    }
    int hash(int key)
    {
        return key % siz;
    }

    list<int>::iterator search(int key)
    {
        int i = hash(key);
        return find(m[i].begin(), m[i].end(), key);
    }

    void add(int key)
    {
        if (contains(key))
            return;
        int i = hash(key);
        m[i].push_back(key);
    }

    void remove(int key)
    {
        if (!contains(key))
            return;
        int i = hash(key);

        m[i].erase(search(key));
    }

    bool contains(int key)
    {
        int i = hash(key);

        if (search(key) != m[i].end())
            return true;
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
