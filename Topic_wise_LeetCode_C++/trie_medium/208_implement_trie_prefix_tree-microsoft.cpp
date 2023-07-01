/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

// Leetcode solution java On time, On space
// class TrieNode {

//     // R links to node children
//     private TrieNode[] links;

//     private final int R = 26;

//     private boolean isEnd;

//     public TrieNode() {
//         links = new TrieNode[R];
//     }

//     public boolean containsKey(char ch) {
//         return links[ch -'a'] != null;
//     }
//     public TrieNode get(char ch) {
//         return links[ch -'a'];
//     }
//     public void put(char ch, TrieNode node) {
//         links[ch -'a'] = node;
//     }
//     public void setEnd() {
//         isEnd = true;
//     }
//     public boolean isEnd() {
//         return isEnd;
//     }
// }
// class Trie
// {
// private
//     TrieNode root;

// public
//     Trie()
//     {
//         root = new TrieNode();
//     }

//     // Inserts a word into the trie.
// public
//     void insert(String word)
//     {
//         TrieNode node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             char currentChar = word.charAt(i);
//             if (!node.containsKey(currentChar))
//             {
//                 node.put(currentChar, new TrieNode());
//             }
//             node = node.get(currentChar);
//         }
//         node.setEnd();
//     }
// }
// class Trie
// {
//     ...

//         // search a prefix or whole key in trie and
//         // returns the node where search ends
//         private TrieNode
//         searchPrefix(String word)
//     {
//         TrieNode node = root;
//         for (int i = 0; i < word.length(); i++)
//         {
//             char curLetter = word.charAt(i);
//             if (node.containsKey(curLetter))
//             {
//                 node = node.get(curLetter);
//             }
//             else
//             {
//                 return null;
//             }
//         }
//         return node;
//     }

//     // Returns if the word is in the trie.
// public
//     boolean search(String word)
//     {
//         TrieNode node = searchPrefix(word);
//         return node != null && node.isEnd();
//     }
// }
// class Trie
// {
//     ...

//         // Returns if there is any word in the trie
//         // that starts with the given prefix.
//         public boolean
//         startsWith(String prefix)
//     {
//         TrieNode node = searchPrefix(prefix);
//         return node != null;
//     }
// }

// Techdose solution On time, On space similar to my solution
#define MAX_NODES 10000
class Trie
{
    struct Trienode
    {
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
    };
    Trienode *root;

    Trienode *getNode(int index)
    {
        Trienode *newnode = new Trienode;
        newnode->val = 'a' + index;
        newnode->count = newnode->endsHere = 0;
        for (int i = 0; i < 26; ++i)
            newnode->child[i] = NULL;
        return newnode;
    }

public:
    /** Initialize your data structure here. */
    Trie()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/' - 'a');
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trienode *curr = root;
        int index;
        for (int i = 0; word[i] != '\0'; ++i)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode(index);
            curr->child[index]->count += 1;
            curr = curr->child[index];
        }
        curr->endsHere += 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trienode *curr = root;
        int index;
        for (int i = 0; word[i] != '\0'; ++i)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trienode *curr = root;
        int index;
        for (int i = 0; prefix[i] != '\0'; ++i)
        {
            index = prefix[i] - 'a';
            if (curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// My solution On time, On space
// class Node
// {
// public:
//     char c;
//     bool end = false;
//     vector<Node *> children = vector<Node *>(26, NULL);
//     Node(char ch)
//     {
//         c = ch;
//     }
// };

// class Trie
// {
// public:
//     Node *root;
//     Trie()
//     {
//         root = new Node(' ');
//     }

//     void insert(string word)
//     {
//         Node *curr = root;
//         for (char c : word)
//         {
//             if (curr->children[c - 'a'] == NULL)
//             {
//                 curr->children[c - 'a'] = new Node(c);
//             }
//             curr = curr->children[c - 'a'];
//         }

//         curr->end = true;
//     }

//     bool search(string word)
//     {
//         Node *curr = root;
//         for (char c : word)
//         {
//             if (curr->children[c - 'a'] == NULL)
//             {
//                 return false;
//             }
//             curr = curr->children[c - 'a'];
//         }

//         if (curr != NULL && curr->end == true)
//             return true;
//         else
//             return false;
//     }

//     bool startsWith(string prefix)
//     {
//         Node *curr = root;
//         for (char c : prefix)
//         {
//             if (curr->children[c - 'a'] == NULL)
//             {
//                 return false;
//             }
//             curr = curr->children[c - 'a'];
//         }

//         return true;
//     }
// };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
