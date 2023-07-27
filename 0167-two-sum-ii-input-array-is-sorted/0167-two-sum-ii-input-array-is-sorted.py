class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # binary search
        low = 0
        high = len(numbers) - 1
        
        while ( (low < len(numbers)) and
                 (numbers[low] + numbers[high] != target) and
                 (high >= 0)
                ):
            result = numbers[low] + numbers[high] 
            if result < target:
                low+=1
            else:
                high-=1
                
        return [low+1,high+1]
        