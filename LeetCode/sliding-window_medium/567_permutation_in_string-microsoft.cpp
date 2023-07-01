/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // Neetcode solution On*26 time On*26 space
    // Leetcode solution approaches
    bool isEmpty(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false;
        vector<int> arr(26);
        // add the values to the hash array
        for (int i = 0; i < s1.size(); i++)
        {
            arr[s1[i] - 'a']++;
        }
        int i = 0;
        int j = 0;
        // point j to it's position
        for (; j < s1.size(); j++)
        {
            arr[s2[j] - 'a']--;
        }
        j--;
        if (isEmpty(arr))
            return true;
        while (j < s2.size())
        {
            arr[s2[i] - 'a']++;
            // remove old character from hash
            i++;
            j++;
            if (j < s2.size())
                arr[s2[j] - 'a']--;
            // append new character to hash

            if (isEmpty(arr))
                return true;
        }
        return isEmpty(arr);
    }

    // Approach 1 create all permutations of s1 On! time On^2 space

    //     public class Solution {
    //     boolean flag = false;

    //     public boolean checkInclusion(String s1, String s2) {
    //         permute(s1, s2, 0);
    //         return flag;
    //     }

    //     public String swap(String s, int i0, int i1) {
    //         if (i0 == i1)
    //             return s;
    //         String s1 = s.substring(0, i0);
    //         String s2 = s.substring(i0 + 1, i1);
    //         String s3 = s.substring(i1 + 1);
    //         return s1 + s.charAt(i1) + s2 + s.charAt(i0) + s3;
    //     }

    //     void permute(String s1, String s2, int l) {
    //         if (l == s1.length()) {
    //             if (s2.indexOf(s1) >= 0)
    //                 flag = true;
    //         } else {
    //             for (int i = l; i < s1.length(); i++) {
    //                 s1 = swap(s1, l, i);
    //                 permute(s1, s2, l + 1);
    //                 s1 = swap(s1, l, i);
    //             }
    //         }
    //     }
    // }

    // Approach 2 sorting, sorted(x) == sorted(y) Os1logs1 + (s2-s1)s1logs1 time logs1 space
    // public class Solution {
    // public boolean checkInclusion(String s1, String s2) {
    //     s1 = sort(s1);
    //     for (int i = 0; i <= s2.length() - s1.length(); i++) {
    //         if (s1.equals(sort(s2.substring(i, i + s1.length()))))
    //             return true;
    //     }
    //     return false;
    // }

    // public String sort(String s) {
    //     char[] t = s.toCharArray();
    //     Arrays.sort(t);
    //     return new String(t);
    // }
    // }

    // Approach 3 Using Hashmap to store frequency of character Os1+26s1(s2-s1) time O1 space
    // public class Solution {
    // public boolean checkInclusion(String s1, String s2) {
    //     if (s1.length() > s2.length())
    //         return false;
    //     HashMap<Character, Integer> s1map = new HashMap<>();

    //     for (int i = 0; i < s1.length(); i++)
    //         s1map.put(s1.charAt(i), s1map.getOrDefault(s1.charAt(i), 0) + 1);

    //     for (int i = 0; i <= s2.length() - s1.length(); i++) {
    //         HashMap<Character, Integer> s2map = new HashMap<>();
    //         for (int j = 0; j < s1.length(); j++) {
    //             s2map.put(s2.charAt(i + j), s2map.getOrDefault(s2.charAt(i + j), 0) + 1);
    //         }
    //         if (matches(s1map, s2map))
    //             return true;
    //     }
    //     return false;
    // }

    // public boolean matches(HashMap<Character, Integer> s1map, HashMap<Character, Integer> s2map) {
    //     for (char key : s1map.keySet()) {
    //         if (s1map.get(key) - s2map.getOrDefault(key, -1) != 0)
    //             return false;
    //     }
    //     return true;
    // }
    // }

    // Approach  4 using array inplace of hashmap Os1+26(s2-s1) time O1 space
    //     public class Solution {
    //     public boolean checkInclusion(String s1, String s2) {
    //         if (s1.length() > s2.length())
    //             return false;
    //         int[] s1map = new int[26];
    //         for (int i = 0; i < s1.length(); i++)
    //             s1map[s1.charAt(i) - 'a']++;
    //         for (int i = 0; i <= s2.length() - s1.length(); i++) {
    //             int[] s2map = new int[26];
    //             for (int j = 0; j < s1.length(); j++) {
    //                 s2map[s2.charAt(i + j) - 'a']++;
    //             }
    //             if (matches(s1map, s2map))
    //                 return true;
    //         }
    //         return false;
    //     }

    //     public boolean matches(int[] s1map, int[] s2map) {
    //         for (int i = 0; i < 26; i++) {
    //             if (s1map[i] != s2map[i])
    //                 return false;
    //         }
    //         return true;
    //     }
    // }

    // Approach 5 Sliding window Os1+26(s2-s1) time O1 space
    //     public class Solution {
    //     public boolean checkInclusion(String s1, String s2) {
    //         if (s1.length() > s2.length())
    //             return false;
    //         int[] s1map = new int[26];
    //         int[] s2map = new int[26];
    //         for (int i = 0; i < s1.length(); i++) {
    //             s1map[s1.charAt(i) - 'a']++;
    //             s2map[s2.charAt(i) - 'a']++;
    //         }
    //         for (int i = 0; i < s2.length() - s1.length(); i++) {
    //             if (matches(s1map, s2map))
    //                 return true;
    //             s2map[s2.charAt(i + s1.length()) - 'a']++;
    //             s2map[s2.charAt(i) - 'a']--;
    //         }
    //         return matches(s1map, s2map);
    //     }

    //     public boolean matches(int[] s1map, int[] s2map) {
    //         for (int i = 0; i < 26; i++) {
    //             if (s1map[i] != s2map[i])
    //                 return false;
    //         }
    //         return true;
    //     }
    // }

    // Approach 6 Sliding window optimal Os1+(s2-s1) time O1 space
    // public class Solution {
    //     public boolean checkInclusion(String s1, String s2) {
    //         if (s1.length() > s2.length())
    //             return false;
    //         int[] s1map = new int[26];
    //         int[] s2map = new int[26];
    //         for (int i = 0; i < s1.length(); i++) {
    //             s1map[s1.charAt(i) - 'a']++;
    //             s2map[s2.charAt(i) - 'a']++;
    //         }

    //         int count = 0;
    //         for (int i = 0; i < 26; i++) {
    //             if (s1map[i] == s2map[i])
    //                 count++;
    //         }

    //         for (int i = 0; i < s2.length() - s1.length(); i++) {
    //             int r = s2.charAt(i + s1.length()) - 'a', l = s2.charAt(i) - 'a';
    //             if (count == 26)
    //                 return true;
    //             s2map[r]++;
    //             if (s2map[r] == s1map[r]) {
    //                 count++;
    //             } else if (s2map[r] == s1map[r] + 1) {
    //                 count--;
    //             }
    //             s2map[l]--;
    //             if (s2map[l] == s1map[l]) {
    //                 count++;
    //             } else if (s2map[l] == s1map[l] - 1) {
    //                 count--;
    //             }
    //         }
    //         return count == 26;
    //     }
    // }
};
// @lc code=end
