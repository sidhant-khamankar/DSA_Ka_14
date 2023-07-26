class Solution:
    def isPalindrome(self, s: str) -> bool:
        # built in functions
        # O(n) time O(1) space
        s_al_num = ''.join(char for char in s if char.isalnum()).lower()
        # print(s_al_num)
        # print(s_al_num[::-1])
        if s_al_num == s_al_num[::-1]:
            return True
        return False
        