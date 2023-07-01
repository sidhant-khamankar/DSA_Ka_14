/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start

// My solution Om+n time Omax(m,n) space
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        // vector<int> v1;
        // stringstream ss1(version1);
        // string rev1;
        // while (getline(ss1, rev1, '.'))
        // {
        //     int i = 0;
        //     while (i < rev1.size() && rev1[i] == '0')
        //         i++;
        //     if (i < rev1.size())
        //     {
        //         int temp = stoi(rev1.substr(i, rev1.size() - i));
        //         v1.push_back(temp);
        //     }
        //     else
        //         v1.push_back(0);
        // }

        // vector<int> v2;
        // stringstream ss2(version2);
        // string rev2;
        // while (getline(ss2, rev2, '.'))
        // {
        //     int i = 0;
        //     while (i < rev2.size() && rev2[i] == '0')
        //         i++;
        //     if (i < rev2.size())
        //     {
        //         int temp = stoi(rev2.substr(i, rev2.size() - i));
        //         v2.push_back(temp);
        //     }
        //     else
        //         v2.push_back(0);
        // }

        // if (v1.size() > v2.size())
        // {
        //     for (int i = v2.size(); i < v1.size(); i++)
        //         v2.push_back(0);
        // }
        // else if (v1.size() < v2.size())
        // {
        //     for (int i = v1.size(); i < v2.size(); i++)
        //         v1.push_back(0);
        // }

        // // for (int k = 0; k < v1.size(); k++)
        // //     cout << v1[k] << " ";
        // // cout << "\n\n";
        // // for (int k = 0; k < v2.size(); k++)
        // //     cout << v2[k] << " ";
        // // cout << "\n\n";

        // int i = 0, j = 0;
        // while (i < v1.size() && j < v2.size())
        // {
        //     if (v1[i] < v2[j])
        //         return -1;
        //     else if (v1[i] > v2[j])
        //         return 1;
        //     i++;
        //     j++;
        // }

        // return 0;

        //Code for cause solution On+m time
        int d1 = count(version1.begin(), version1.end(), '.');
        int d2 = count(version2.begin(), version2.end(), '.');

        int dif = abs(d1 - d2);

        if (d1 > d2)
            while (dif--)
                version2 += ".0";
        else if (d1 < d2)
            while (dif--)
                version1 += ".0";

        replace(version1.begin(0, version1.end(0, '.', ' ')));
        replace(version2.begin(0, version2.end(0, '.', ' ')));

        stringstream ss1(version1), ss2(version2);

        int n1, n2;

        while (ss1 >> n1)
        {
            ss2 >> n2;

            if (n1 < n2)
                return -1;
            else if (n2 < n1)
                return 1;
        }

        return 0;
    }
};
// @lc code=end
