/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

//did not get
//Striver solution Ologn time
struct Node
{
    int key, value, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    /** add new node into head of list and increase list size by 1 **/
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    /** remove input node and decrease list size by 1**/
    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(Node *node)
    {
        // remove node from key and freqList maps
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        // if current list is the last list which has lowest frequency and current node is the only node in that list
        // we need to remove the entire list and then increase min frequency value by 1
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        // add current node to another list has current frequency + 1,
        // if we do not have the list with this frequency, initialize it
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);          //add to front
        freqListMap[node->cnt] = nextHigherFreqList; //add to freqListMap and keyNode maps
        keyNode[node->key] = node;
    }

    /** get node value by key, and then update node frequency as well as relocate that node **/
    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    /**
     * add new node into LFU cache, as well as double linked list
     * condition 1: if LFU cache has input key, update node value and node position in list
     * condition 2: if LFU cache does NOT have input key
     *  - sub condition 1: if LFU cache does NOT have enough space, remove the Least Recent Used node
     *  in minimum frequency list, then add new node
     *  - sub condition 2: if LFU cache has enough space, add new node directly
     * **/
    void put(int key, int value)
    {
        // corner case: check cache capacity initialization
        if (maxSizeCache == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end()) // key already present, update value and update freq
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else //add new key
        {
            if (curSize == maxSizeCache) // full
            {
                // get minimum frequency list
                List *list = freqListMap[minFreq];
                // remove LRU from keyNode and freqListMap
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            // new value has to be added who is not there previously
            // reset min frequency to 1 because of adding new node
            minFreq = 1;

            // get the list with frequency 1, and then add new node into the list, as well as into LFU cache
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node); //add to front

            // add to keyNode and freqListMap
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
