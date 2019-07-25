class Solution:
    def reverse(self, x: int) -> int:
        
        if x >= 2**31-1 or x <= -2**31: return 0
        else:
            strX = str(x)               #change x to the str form so that I can operate x easily
            
        if x >= 0 :
            revst = strX[::-1]          #This is the key point
        else:
            temp = strX[1:] 
            temp2 = temp[::-1] 
            revst = "-" + temp2
            
        if int(revst) >= 2**31-1 or int(revst) <= -2**31: return 0
        else: return int(revst)