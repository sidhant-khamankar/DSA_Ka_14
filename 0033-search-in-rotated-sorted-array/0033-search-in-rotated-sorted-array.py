# striver solution O(logn) time O1 space
# like neetcode solution
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if target == nums[mid]:
                return mid

            # left sorted portion
            if nums[l] <= nums[mid]:
                
                if target >= nums[l] and target <= nums[mid]:
                    r = mid - 1
                    # remain in left sorted portion
                else:
                    # move to right portion
                    l = mid + 1
            
            # right sorted portion
            else:
                if target >= nums[mid] and target <= nums[r]:
                    # remain in right sorted portion
                    l = mid + 1
                else:
                    # move to left portion
                    r = mid - 1
            
        
        return -1
