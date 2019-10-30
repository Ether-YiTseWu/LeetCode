class Solution:
    def isHappy(self, n: int) -> bool:
        nStr = str(n)
        checkList = []
        while(1):
            sumNum = 0
            for i in range(0,len(nStr)):
                sumNum = sumNum + int(nStr[i])*int(nStr[i])
            if sumNum == 1:
                return 1 
            elif sumNum in checkList:
                return 0
            checkList.append(sumNum);
            nStr = str(sumNum)
