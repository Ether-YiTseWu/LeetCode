class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        smallLen = 100
        for word in strs:
            temp = len(word)
            if temp < smallLen:
                smallLen = temp                      # acquire the most shortest string length in strs
                
        sameNum = 0
        for i in range(smallLen):
            tempCount = 0
            for word in strs:
                if word[i] == strs[0][i]:
                    tempCount = tempCount + 1
            if tempCount != len(strs): break
            if tempCount == len(strs):
                sameNum = sameNum + 1                # compute the number of same letters in strs
                
        if len(strs) == 0 :
            return('')
        else:
            return strs[0][0:sameNum]                # output
                
