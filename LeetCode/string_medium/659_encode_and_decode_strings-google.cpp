// My solution On^2 time
// str.find(string to find, position to find from)
// str.substr(starting position, size of the substring)
// str.erase(starting position, size to erase)

// Neetcode solution On time

class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        // write your code here
        string s;
        for (int i = 0; i < strs.size(); i++)
        {
            if (i == 0)
                s = strs[i];
            else
                s += "|`|" + strs[i];
        }

        return s;

        // string result = "";

        // for (int i = 0; i < strs.size(); i++) {
        //     string str = strs[i];
        //     result += to_string(str.size()) + "#" + str;
        // }

        // return result;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        // write your code here
        vector<string> res;

        string token;
        int pos = 0;

        while ((pos = str.find("|`|")) != string::npos)
        {
            token = str.substr(0, pos); // store the substring
            res.push_back(token);
            str.erase(0, pos + 3);
        }
        res.push_back(str);

        return res;

        // vector<string> result;

        // int i = 0;
        // while (i < s.size()) {
        //     int j = i;
        //     while (s[j] != '#') {
        //         j++;
        //     }
        //     int length = stoi(s.substr(i, j - i));
        //     string str = s.substr(j + 1, length);
        //     result.push_back(str);
        //     i = j + 1 + length;
        // }

        // return result;
    }
};