# Did not get

# Neetcode solution
# Time: log(min(n, m))


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        A, B = nums1, nums2
        total = len(nums1) + len(nums2)
        half = total // 2
        
        # apply binary search on smaller array
        if len(B) < len(A):
            A, B = B, A
            
        # consider half lengths from array A and B for creating left half of final array. Cut the smaller array using binary search and take remaining elements of combined array's left half portion from bigger array. If it is valid partition calculate median depending upon total number of elements in combined array. If partition is not valid move the middle in smaller array using binary search

        # A is smaller array
        l, r = 0, len(A) - 1
        while True:
            # left partition lengths i.e. part of left half of combined array
            i = (l + r) // 2  # A
            # j is index so getting it value from two lengths
            j = half - 1 - i - 1  # B
            
            # add negative infinity to front and positive infinity at end of these arrays 
            Aleft = A[i] if i >= 0 else float("-infinity")
            # if i<0 that means left portion has only elements from array B which is valid partition so next check should pass
            
            Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")
            # when i + 1>len(A) then all elements of array A are in combined array's left portion which is valid partition so next check should pass
            
            Bleft = B[j] if j >= 0 else float("-infinity")
            Bright = B[j + 1] if (j + 1) < len(B) else float("infinity")

            # partition is correct
            if Aleft <= Bright and Bleft <= Aright:
                # odd number of elements in combined array
                if total % 2:
                    return min(Aright, Bright)
                # even number of elements in combined array
                
                # decimal division
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            
            elif Aleft > Bright:
                # too many elements from A is there 
                # so reduce considered size from A thereby considering smaller numbers from A to make Aleft smaller
                r = i - 1
            else:
                # make Aright bigger and increase mid so as to consider less elements from B array for combined array's left portion thereby making Bleft smaller
                l = i + 1
