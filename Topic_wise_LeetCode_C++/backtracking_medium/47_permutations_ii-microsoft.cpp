/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    // did not remember swap

    //leetcode solution On!*n time On hash map and auxiliary recursion space
    // public
    //     List<List<Integer>> permuteUnique(int[] nums)
    //     {
    //         List<List<Integer>> results = new ArrayList<>();

    //         // count the occurrence of each number
    //         HashMap<Integer, Integer> counter = new HashMap<>();
    //         for (int num : nums)
    //         {
    //             if (!counter.containsKey(num))
    //                 counter.put(num, 0);
    //             counter.put(num, counter.get(num) + 1);
    //         }

    //         LinkedList<Integer> comb = new LinkedList<>();
    //         this.backtrack(comb, nums.length, counter, results);
    //         return results;
    //     }

    // protected
    //     void backtrack(
    //         LinkedList<Integer> comb,
    //         Integer N,
    //         HashMap<Integer, Integer> counter,
    //         List<List<Integer>> results)
    //     {

    //         if (comb.size() == N)
    //         {
    //             // make a deep copy of the resulting permutation,
    //             // since the permutation would be backtracked later.
    //             results.add(new ArrayList<Integer>(comb));
    //             return;
    //         }

    //         for (Map.Entry<Integer, Integer> entry : counter.entrySet())
    //         {
    //             Integer num = entry.getKey();
    //             Integer count = entry.getValue();
    //             if (count == 0)
    //                 continue;
    //             // add this number into the current combination
    //             comb.addLast(num);
    //             counter.put(num, count - 1);

    //             // continue the exploration
    //             backtrack(comb, N, counter, results);

    //             // revert the choice for the next exploration
    //             comb.removeLast();
    //             counter.put(num, count);
    //         }
    //     }

    // Striver solution Approach 2 On!*n time On auxiliary space
    void recurPermute(int index, vector<int> &nums, set<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.insert(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> ans;
        recurPermute(0, nums, ans);
        vector<vector<int>> v;
        v.assign(ans.begin(), ans.end());
        return v;
    }
};

// @lc code=end
