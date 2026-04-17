# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        q1 = [p]
        q2 = [q]

        while q1 and q2:
            n1 = q1.pop()
            n2 = q2.pop()

            if not n1 and not n2:
                continue
            if not n1 or not n2:
                return False
            
            if n1.val == n2.val:
                q1.append(n1.left)
                q1.append(n1.right)
                q2.append(n2.left)
                q2.append(n2.right)
            else:
                return False

        return True

