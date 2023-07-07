from itertools import permutations
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Time O(m*nlogn)
        # Space O(n)
        strs_table = {}
        # O(m)
        for string in strs:
            # O(nlogn)
            sorted_string = ''.join(sorted(string))

            # O(1)
            if sorted_string not in strs_table:
                strs_table[sorted_string] = []

            # O(1)
            strs_table[sorted_string].append(string)

        return list(strs_table.values())
       