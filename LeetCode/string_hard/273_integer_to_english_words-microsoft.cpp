/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution
{
public:
    // InterviewPrep HelloWorld Video Java
    // My solution On time On space
    string get_hundred_string(vector<int> hundred, unordered_map<int, string> &mp)
    {
        string s_hundred;
        if (hundred.size() > 0)
        {
            if (hundred.size() > 2)
            {
                if (hundred[0] != 0)
                {
                    s_hundred += " ";
                    s_hundred += mp[hundred[0]];
                    s_hundred += " Hundred";
                }
                if (hundred[1] != 0)
                {
                    s_hundred += " ";
                    if (hundred[1] == 1)
                        s_hundred += mp[stoi(to_string(hundred[1]) + to_string(hundred[2]))];
                    else
                        s_hundred += mp[stoi(to_string(hundred[1]) + '0')];
                }
                if (hundred[2] != 0 && hundred[1] != 1)
                {
                    s_hundred += " ";
                    s_hundred += mp[hundred[2]];
                }
            }
            else if (hundred.size() > 1)
            {
                if (hundred[0] != 0)
                {
                    s_hundred += " ";
                    if (hundred[0] == 1)
                        s_hundred += mp[stoi(to_string(hundred[0]) + to_string(hundred[1]))];
                    else
                        s_hundred += mp[stoi(to_string(hundred[0]) + '0')];
                }
                if (hundred[1] != 0 && hundred[0] != 1)
                {
                    s_hundred += " ";
                    s_hundred += mp[hundred[1]];
                }
            }
            else if (hundred.size() == 1)
            {
                s_hundred += " ";
                s_hundred += mp[hundred[0]];
            }
        }

        return s_hundred;
    }
    string numberToWords(int num)
    {
        // map
        unordered_map<int, string> mp;
        mp[0] = "Zero"; // ignore for more than one digit in hundred
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
        mp[100] = "Hundred";

        // hundred bucket
        vector<int> hundred;
        // thousand bucket
        vector<int> thousand;
        // million bucket
        vector<int> million;
        // billion bucket
        vector<int> billion;

        if (num == 0)
        {
            return "Zero";
        }
        // traverse from last
        while (num != 0)
        {
            if (hundred.size() < 3)
                hundred.push_back(num % 10);
            else if (thousand.size() < 3)
                thousand.push_back(num % 10);
            else if (million.size() < 3)
                million.push_back(num % 10);
            else if (billion.size() < 3)
                billion.push_back(num % 10);
            num = num / 10;
        }

        reverse(hundred.begin(), hundred.end());
        reverse(thousand.begin(), thousand.end());
        reverse(million.begin(), million.end());
        reverse(billion.begin(), billion.end());

        string s_hundred = get_hundred_string(hundred, mp);

        string s_thousand = get_hundred_string(thousand, mp);
        if (s_thousand.size() > 0)
            s_thousand += " Thousand";

        string s_million = get_hundred_string(million, mp);
        if (s_million.size() > 0)
            s_million += " Million";

        string s_billion = get_hundred_string(billion, mp);
        if (s_billion.size() > 0)
            s_billion += " Billion";

        string ans = s_billion + s_million + s_thousand + s_hundred;
        if (ans[0] == ' ')
        {
            ans.erase(0, 1);
        }

        return ans;
    }
    // 1234567
};
// @lc code=end
