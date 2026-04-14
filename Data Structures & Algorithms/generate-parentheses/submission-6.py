class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def dfs(currentStr, bal):
            if bal < 0:
                return

            if len(currentStr) == (2*n):
                if bal == 0:
                    result.append(currentStr)
                    return
                else:
                    return
            
            dfs(currentStr + ")", bal - 1)
            dfs(currentStr + "(", bal + 1)

        dfs("", 0)

        return result