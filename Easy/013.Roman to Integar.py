class Solution:
    def romanToInt(self, s: str) -> int:
        RomanSymbol = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000} # key point : build a dictionary.
        ans = 0
        for i in range(len(s)):
            ans = ans + RomanSymbol[s[i]]
            if i >= 1 and RomanSymbol[s[i]] > RomanSymbol[s[i-1]]:
                ans = ans - RomanSymbol[s[i-1]]*2
        return ans
