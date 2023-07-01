/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{

    // Leetcode solution like quick sort  - Hoare's selection algorithm quickselect, Lomuto's Partition
    // On master theorem average On^2 worst time On space

private:
    vector<int> unique;
    map<int, int> count_map;

public:
    int partition(int left, int right, int pivot_index)
    {
        int pivot_frequency = this->count_map[this->unique[pivot_index]];
        // 1. move pivot to the end
        swap(this->unique[pivot_index], this->unique[right]);

        // 2. move all less frequent elements to the left
        int store_index = left;
        for (int i = left; i <= right; i++)
        {
            if (this->count_map[this->unique[i]] < pivot_frequency)
            {
                swap(this->unique[store_index], this->unique[i]);
                store_index += 1;
            }
        }

        // 3. move pivot to its final place
        swap(this->unique[right], this->unique[store_index]);

        return store_index;
    }

    void quickselect(int left, int right, int k_smallest)
    {
        /*
        Sort a list within left..right till kth less frequent element
        takes its place. 
        */

        // base case: the list contains only one element
        if (left == right)
            return;

        int pivot_index = left + rand() % (right - left + 1);

        // find the pivot position in a sorted list
        pivot_index = partition(left, right, pivot_index);

        // if the pivot is in its final sorted position
        if (k_smallest == pivot_index)
        {
            return;
        }
        else if (k_smallest < pivot_index)
        {
            // go left
            quickselect(left, pivot_index - 1, k_smallest);
        }
        else
        {
            // go right
            quickselect(pivot_index + 1, right, k_smallest);
        }
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // build hash map : element and how often it appears
        for (int n : nums)
        {
            this->count_map[n] += 1;
        }

        // array of unique elements
        size_t n = this->count_map.size();
        for (pair<int, int> p : this->count_map)
        {
            this->unique.push_back(p.first);
        }

        // kth top frequent element is (n - k)th less frequent.
        // Do a partial sort: from less frequent to the most frequent, till
        // (n - k)th less frequent element takes its place (n - k) in a sorted array.
        // All element on the left are less frequent.
        // All the elements on the right are more frequent.
        quickselect(0, n - 1, n - k);
        // Return top k frequent elements
        vector<int> top_k_frequent(k);
        copy(this->unique.begin() + n - k, this->unique.end(), top_k_frequent.begin());
        return top_k_frequent;
    }

public:
    // Leetcode , Aditya Verma Solution
    // After the first k elements we start to push and pop at each step, N - k steps in total.
    // Onlogk time On+k space

    // vector<int> topKFrequent(vector<int> &nums, int k)
    // {
    //     // O(1) time
    //     if (k == nums.size())
    //     {
    //         return nums;
    //     }

    //     // 1. build hash map : element and how often it appears
    //     // O(N) time
    //     map<int, int> count_map;
    //     for (int n : nums)
    //     {
    //         count_map[n] += 1;
    //     }

    //     // initialise a heap with most frequent elements at the top
    //     auto comp = [&count_map](int n1, int n2) //did not understand
    //     { return count_map[n1] > count_map[n2]; };
    //     priority_queue<int, vector<int>, decltype(comp)> heap(comp);

    //     // 2. keep k top fequent elements in the heap
    //     // O(N log k) < O(N log N) time
    //     for (pair<int, int> p : count_map)
    //     {
    //         heap.push(p.first);
    //         if (heap.size() > k)
    //             heap.pop();
    //     }

    //     // 3. build an output array
    //     // O(k log k) time
    //     vector<int> top(k);
    //     for (int i = k - 1; i >= 0; i--)
    //     {
    //         top[i] = heap.top();
    //         heap.pop();
    //     }
    //     return top;
    // }

    // My solution, just added all n to heap Onlogn priority queue rearrangement for n iterms time O2n space
    // vector<int> topKFrequent(vector<int> &nums, int k)
    // {
    //     //3.57
    //     unordered_map<int, int> mp;

    //     for (int e : nums)
    //     {
    //         mp[e]++;
    //     }

    //     priority_queue<pair<int, int>> pq;

    //     for (pair<int, int> p : mp)
    //     {
    //         // cout << p.first << " " << p.second << endl;
    //         pq.push({p.second, p.first});
    //     }

    //     // while (!pq.empty())
    //     // {
    //     //     cout << pq.top().first << " " << pq.top().second << endl;
    //     //     pq.pop();
    //     // }

    //     vector<int> ans;
    //     for (int i = 0; i < k; i++)
    //     {
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }

    //     return ans;
    // }
};
// @lc code=end
