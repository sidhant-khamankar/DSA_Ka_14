class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_elements = [set() for i in range(len(board))]
        column_elements = [set() for i in range(len(board[0]))]
        grid_elements = [set() for i in range(9)]
        
        # O(n*n) time O(1) hashset search,add time
        for i in range(len(board)):
            for j in range(len(board[0])):
                element = board[i][j]
                if element == ".":
                    continue
                if element in row_elements[i]:
                    return False
                row_elements[i].add(element)
                
                if element in column_elements[j]:
                    return False
                column_elements[j].add(element)
                
                if i<=2:
                    if j<=2:
                        if element in grid_elements[0]:
                            return False
                        grid_elements[0].add(element)
                    elif j <= 5:
                        if element in grid_elements[1]:
                            return False
                        grid_elements[1].add(element)
                    else:
                        if element in grid_elements[2]:
                            return False
                        grid_elements[2].add(element)
                elif i<= 5:
                    if j<=2:
                        if element in grid_elements[3]:
                            return False
                        grid_elements[3].add(element)

                    elif j <= 5:
                        if element in grid_elements[4]:
                            return False
                        grid_elements[4].add(element)
                        
                    else:
                        if element in grid_elements[5]:
                            return False
                        grid_elements[5].add(element)
                else:
                    if j<=2:
                        if element in grid_elements[6]:
                            return False
                        grid_elements[6].add(element)
                    elif j <= 5:
                        if element in grid_elements[7]:
                            return False
                        grid_elements[7].add(element)
                    else:
                        if element in grid_elements[8]:
                            return False
                        grid_elements[8].add(element)
        return True
                
                
        
        