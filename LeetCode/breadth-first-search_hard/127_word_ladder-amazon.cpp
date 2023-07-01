/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution
{
public:
    //My solution with autopilot
    //26* length of word* no. of words time Owordlist space
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;
        else
        {
            queue<string> q;
            q.push(beginWord);
            int level = 1;
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    string word = q.front();
                    q.pop();
                    if (word == endWord)
                        return level;
                    for (int j = 0; j < word.size(); j++)
                    {
                        char c = word[j];
                        for (int k = 0; k < 26; k++)
                        {
                            word[j] = 'a' + k;
                            if (dict.find(word) != dict.end())
                            {
                                q.push(word);
                                dict.erase(word);
                            }
                        }
                        word[j] = c;
                    }
                }
                level++;
            }
            return 0;
        }
    }

    //Techdose solution
    //26* length of word* no. of words Owordlist space
    // int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    // {
    //     unordered_set<string> myset;
    //     bool isPresent = false; //Checks if endWord is present in Dict
    //     //Insert all words from Dict in myset
    //     for (auto word : wordList)
    //     {
    //         if (endWord.compare(word) == 0)
    //             isPresent = true;
    //         myset.insert(word); //Insert word in Dict
    //     }
    //     if (isPresent == false) //endWord is not present in Dict
    //         return 0;

    //     queue<string> q;
    //     q.push(beginWord);
    //     int depth = 0;

    //     while (!q.empty())
    //     {
    //         depth += 1;
    //         int lsize = q.size(); //No of elements at a level
    //         while (lsize--)
    //         {
    //             string curr = q.front();
    //             q.pop();
    //             //check for all possible 1 depth words
    //             for (int i = 0; i < curr.length(); ++i) //For each index
    //             {
    //                 string temp = curr;
    //                 for (char c = 'a'; c <= 'z'; ++c) //Try all possible chars
    //                 {
    //                     temp[i] = c;
    //                     if (curr.compare(temp) == 0)
    //                         continue; //Skip the same word
    //                     if (temp.compare(endWord) == 0)
    //                         return depth + 1; //endWord found
    //                     if (myset.find(temp) != myset.end())
    //                     {
    //                         q.push(temp);
    //                         myset.erase(temp);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return 0;
    // }

    // Leetcode solution Om^2n time Om^2n space - explanation in section, m is length of each word, n is number of word
    // class Solution
    // {
    // public
    //     int ladderLength(String beginWord, String endWord, List<String> wordList)
    //     {

    //         // Since all words are of same length.
    //         int L = beginWord.length();

    //         // Dictionary to hold combination of words that can be formed,
    //         // from any given word. By changing one letter at a time.
    //         Map<String, List<String>> allComboDict = new HashMap<>();

    //         wordList.forEach(
    //             word->
    //             {
    //                 for (int i = 0; i < L; i++)
    //                 {
    //                     // Key is the generic word
    //                     // Value is a list of words which have the same intermediate generic word.
    //                     String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
    //                     List<String> transformations = allComboDict.getOrDefault(newWord, new ArrayList<>());
    //                     transformations.add(word);
    //                     allComboDict.put(newWord, transformations);
    //                 }
    //             });

    //         // Queue for BFS
    //         Queue<Pair<String, Integer>> Q = new LinkedList<>();
    //         Q.add(new Pair(beginWord, 1));

    //         // Visited to make sure we don't repeat processing same word.
    //         Map<String, Boolean> visited = new HashMap<>();
    //         visited.put(beginWord, true);

    //         while (!Q.isEmpty())
    //         {
    //             Pair<String, Integer> node = Q.remove();
    //             String word = node.getKey();
    //             int level = node.getValue();
    //             for (int i = 0; i < L; i++)
    //             {

    //                 // Intermediate words for current word
    //                 String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

    //                 // Next states are all the words which share the same intermediate state.
    //                 for (String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<>()))
    //                 {
    //                     // If at any point if we find what we are looking for
    //                     // i.e. the end word - we can return with the answer.
    //                     if (adjacentWord.equals(endWord))
    //                     {
    //                         return level + 1;
    //                     }
    //                     // Otherwise, add it to the BFS Queue. Also mark it visited
    //                     if (!visited.containsKey(adjacentWord))
    //                     {
    //                         visited.put(adjacentWord, true);
    //                         Q.add(new Pair(adjacentWord, level + 1));
    //                     }
    //                 }
    //             }
    //         }

    //         return 0;
    //     }
    // }

    // Leetcode solution bidirectional bfs Om^2n time Om^2n space - explanation in section, m is length of each word, n is number of word
    // class Solution
    // {

    // private
    //     int L;
    // private
    //     Map<String, List<String>> allComboDict;

    //     Solution()
    //     {
    //         this.L = 0;

    //         // Dictionary to hold combination of words that can be formed,
    //         // from any given word. By changing one letter at a time.
    //         this.allComboDict = new HashMap<>();
    //     }

    // private
    //     int visitWordNode(
    //         Queue<Pair<String, Integer>> Q,
    //         Map<String, Integer> visited,
    //         Map<String, Integer> othersVisited)
    //     {

    //         Pair<String, Integer> node = Q.remove();
    //         String word = node.getKey();
    //         int level = node.getValue();

    //         for (int i = 0; i < this.L; i++)
    //         {

    //             // Intermediate words for current word
    //             String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

    //             // Next states are all the words which share the same intermediate state.
    //             for (String adjacentWord : this.allComboDict.getOrDefault(newWord, new ArrayList<>()))
    //             {
    //                 // If at any point if we find what we are looking for
    //                 // i.e. the end word - we can return with the answer.
    //                 if (othersVisited.containsKey(adjacentWord))
    //                 {
    //                     return level + othersVisited.get(adjacentWord);
    //                 }

    //                 if (!visited.containsKey(adjacentWord))
    //                 {

    //                     // Save the level as the value of the dictionary, to save number of hops.
    //                     visited.put(adjacentWord, level + 1);
    //                     Q.add(new Pair(adjacentWord, level + 1));
    //                 }
    //             }
    //         }
    //         return -1;
    //     }

    // public
    //     int ladderLength(String beginWord, String endWord, List<String> wordList)
    //     {

    //         if (!wordList.contains(endWord))
    //         {
    //             return 0;
    //         }

    //         // Since all words are of same length.
    //         this.L = beginWord.length();

    //         wordList.forEach(
    //             word->
    //             {
    //                 for (int i = 0; i < L; i++)
    //                 {
    //                     // Key is the generic word
    //                     // Value is a list of words which have the same intermediate generic word.
    //                     String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
    //                     List<String> transformations =
    //                         this.allComboDict.getOrDefault(newWord, new ArrayList<>());
    //                     transformations.add(word);
    //                     this.allComboDict.put(newWord, transformations);
    //                 }
    //             });

    //         // Queues for birdirectional BFS
    //         // BFS starting from beginWord
    //         Queue<Pair<String, Integer>> Q_begin = new LinkedList<>();
    //         // BFS starting from endWord
    //         Queue<Pair<String, Integer>> Q_end = new LinkedList<>();
    //         Q_begin.add(new Pair(beginWord, 1));
    //         Q_end.add(new Pair(endWord, 1));

    //         // Visited to make sure we don't repeat processing same word.
    //         Map<String, Integer> visitedBegin = new HashMap<>();
    //         Map<String, Integer> visitedEnd = new HashMap<>();
    //         visitedBegin.put(beginWord, 1);
    //         visitedEnd.put(endWord, 1);

    //         while (!Q_begin.isEmpty() && !Q_end.isEmpty())
    //         {

    //             // One hop from begin word
    //             int ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
    //             if (ans > -1)
    //             {
    //                 return ans;
    //             }

    //             // One hop from end word
    //             ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
    //             if (ans > -1)
    //             {
    //                 return ans;
    //             }
    //         }

    //         return 0;
    //     }
    // }
};
// @lc code=end
