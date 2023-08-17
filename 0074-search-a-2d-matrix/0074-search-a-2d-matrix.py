class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        vertical_l = 0
        vertical_h = len(matrix) - 1
        vertical_mid = vertical_l + (vertical_h - vertical_l)//2
        while vertical_l <= vertical_h:
            vertical_mid = vertical_l + (vertical_h - vertical_l)//2
            if matrix[vertical_mid][0] < target:
                vertical_l += 1
            else:
                vertical_h -= 1
                
        if matrix[vertical_mid][0] > target:
            vertical_mid -= 1
        
            
        
        horizontal_l = 0
        horizontal_h = len(matrix[0]) - 1
        horizontal_mid = horizontal_l + (horizontal_h - horizontal_l)//2
        while horizontal_l <= horizontal_h:
            horizontal_mid = horizontal_l + (horizontal_h - horizontal_l)//2
            
            if matrix[vertical_mid][horizontal_mid] == target:
                return True;
            elif matrix[vertical_mid][horizontal_mid] > target:
                horizontal_h -= 1
            else:
                horizontal_l += 1
                
        if matrix[vertical_mid][horizontal_mid] == target:
            return True
        else:
            return False
                
                
        
        