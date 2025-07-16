
# did not get optimal
class Solution:
    # striver optimal approach
    # time O(n), space O(n)
    def subarrayXor(self, arr, k):
        n = len(arr) # size of the given array.
        xr = 0
        from collections import defaultdict
        mpp = defaultdict(int) # declaring the dictionary.
        mpp[xr] = 1 # setting the value of 0.
        cnt = 0
    
        for i in range(n):
            # prefix XOR till index i:
            xr = xr ^ arr[i]
    
            # By formula: x = xr^k:
            x = xr ^ k
    
            # add the occurrence of xr^k
            # to the count:
            cnt += mpp[x]
    
            # Insert the prefix xor till index i
            # into the dictionary:
            mpp[xr] += 1
    
        return cnt
    
    # my solution, striver better approach
    # time O(n^2), space O(1)
    '''
    def subarraysWithXorK(self, a: [int], k: int) -> int:
        n = len(a)  # size of the given array.
        cnt = 0
    
        # Step 1: Generating subarrays:
        for i in range(n):
            xorr = 0
            for j in range(i, n):
    
                # step 2: calculate XOR of all elements:
                xorr = xorr ^ a[j]
    
                # step 3: check XOR and count:
                if (xorr == k):
                    cnt += 1
    
        return cnt
    '''

