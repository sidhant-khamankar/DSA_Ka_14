# My solution like leetcode solution 
# O(1) time 
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = list()
        for s in tokens:
            if s in ['+','-','*','/']:
                second = int(stack.pop())
                first = int(stack.pop())
                res = None
                if s == '+':
                    res = first + second
                elif s == '-':
                    res = first - second
                elif s == '*':
                    res = first * second
                else:
                    res = int(first / second)
                # print(f"{first} {s} {second} : {res}")
                # print(stack)
                stack.append(res)
            else:
                stack.append(s)
        return int(stack[-1])