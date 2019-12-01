class Solution(object):
    def isValid(self, s):
        stack = []
        parentheses = {'(':')', '[':']', '{':'}'}
        for i in s:
            if i in parentheses:
                stack.append(parentheses[i])
            else:
                if not stack or i != stack.pop():
                    return False
        return not stack
