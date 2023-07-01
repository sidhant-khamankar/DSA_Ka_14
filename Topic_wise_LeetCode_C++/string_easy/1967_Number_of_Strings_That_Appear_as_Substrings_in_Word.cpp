//Leetcode discuss solution Omn time

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;
        for (int i = 0; i < patterns.size(); i++)
        {
            if (word.find(patterns[i]) != string::npos) // npos is returned when not found the pattern
                count++;
        }
        return count;
    }
};

// My solution WA on submit
// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {

//         int ans =0;
//         for (string pat : patterns) {
//             int i = 0, j=0;
//             while (i< pat.size() && j<word.size()) {
//                 if (pat[i]!=word[j])
//                     j++;
//                 else if (pat[i]==word[j]) {
//                     i++;
//                     j++;
//                 }
//             }
//             if (i==pat.size())
//                 ans++;

//         }

//         return ans;
//     }
// };
