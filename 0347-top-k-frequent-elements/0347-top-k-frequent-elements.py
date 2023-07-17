class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Hashmap 
        d = defaultdict(int)
        # Traversal O(n)
        for element in nums:
            d[element] += 1

        # element : frequency

        # Sorting O(nlogn)
        return list(k for k, v in sorted(d.items(), key= lambda item: item[1],reverse=True))[:k]