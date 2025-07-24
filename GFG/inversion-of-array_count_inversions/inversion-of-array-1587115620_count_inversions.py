from typing import List
import math

class Solution:
    # did not get
    # striver solution
    # time O(nlogn) space O(n)
    
    def merge(self, arr : List[int], low : int, mid : int, high : int) -> int:
        temp = []   # temporary array
        left = low  # starting index of left half of arr
        right = mid + 1 # starting index of right half of arr
    
        cnt = 0     # Modification 1: cnt variable to count the pairs
    
        # storing elements in the temporary array in a sorted manner
        while (left <= mid and right <= high):
            if (arr[left] <= arr[right]):
                temp.append(arr[left])
                left += 1
            else:
                temp.append(arr[right])
                cnt += (mid - left + 1)  # Modification 2
                right += 1
    
        # if elements on the left half are still left
        while (left <= mid):
            temp.append(arr[left])
            left += 1
    
        # if elements on the right half are still left
        while (right <= high):
            temp.append(arr[right])
            right += 1
    
        # transfering all elements from temporary to arr
        for i in range(low, high + 1):
            arr[i] = temp[i - low]
    
        return cnt   # Modification 3
    
    def mergeSort(self, arr : List[int], low : int, high : int) -> int:
        cnt = 0
        if low >= high:
            return cnt
        mid = math.floor((low + high) / 2)
        cnt += self.mergeSort(arr, low, mid)    # left half
        cnt += self.mergeSort(arr, mid + 1, high)  # right half
        cnt += self.merge(arr, low, mid, high)  # merging sorted halves
        return cnt
    
    def inversionCount(self, arr : List[int]) -> int:
        # Count the number of pairs:
        n = len(arr)
        # Count the number of pairs:
        return self.mergeSort(arr, 0, n - 1)