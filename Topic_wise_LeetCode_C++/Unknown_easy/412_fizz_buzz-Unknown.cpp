/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start

// Leetcode solution for multiple mappings use hash table On time O1 space
//     class Solution
//     {
//     public
//         List<String> fizzBuzz(int n)
//         {

//             // ans list
//             List<String> ans = new ArrayList<String>();

//             // Hash map to store all fizzbuzz mappings.
//             HashMap<Integer, String> fizzBizzDict =
//                 new HashMap<Integer, String>(){
//                     {put(3, "Fizz");
//             put(5, "Buzz");
//         }
//     };

//     for (int num = 1; num <= n; num++)
//     {

//         String numAnsStr = "";

//         for (Integer key : fizzBizzDict.keySet())
//         {

//             // If the num is divisible by key,
//             // then add the corresponding string mapping to current numAnsStr
//             if (num % key == 0)
//             {
//                 numAnsStr += fizzBizzDict.get(key);
//             }
//         }

//         if (numAnsStr.equals(""))
//         {
//             // Not divisible by 3 or 5, add the number
//             numAnsStr += Integer.toString(num);
//         }

//         // Append the current answer str to the ans list
//         ans.add(numAnsStr);
//     }

//     return ans;
// }
// }
class Solution
{
public:
    // My solution, Nick white On time O1 space to_string use
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
                ans.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ans.push_back("Fizz");
            else if (i % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }

        return ans;
    }
};
// @lc code=end
