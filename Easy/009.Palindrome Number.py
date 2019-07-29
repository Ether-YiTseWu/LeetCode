class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        return str(x) == str(x)[::-1]     # [::-1] is a fast way to change str printed from tail to head
