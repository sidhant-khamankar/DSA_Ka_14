# My solution O(2^n*2) time 
class Solution:
    def recur(self, ans, open_brackets, close_brackets, n, output):
        # print(f"{open_brackets}, {close_brackets} - {ans}")
        if len(ans) == n*2:
            output.append(ans)
            return
        
        if open_brackets + 1 <= n:
                self.recur(ans+'(', open_brackets + 1, close_brackets, n, output)
                
        if close_brackets + 1 <= n and open_brackets > close_brackets:
            self.recur(ans+')', open_brackets, close_brackets + 1, n, output)
        
        
        
    def generateParenthesis(self, n: int) -> List[str]:
        # start with open bracket
        # use closing bracket only when there is atleast 1 open bracket
        
        output = list()
        ans = '('
        open_brackets = 1
        close_brackets = 0
        
        self.recur(ans, open_brackets, close_brackets, n, output)
        
        return output
            
            
            
        