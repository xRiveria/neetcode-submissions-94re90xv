# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = []
        stack.append((p, q))

        while stack:
            val = stack.pop()

            if not val[0] and not val[1]:
                continue

            if not val[0] or not val[1] or val[0].val != val[1].val:
                return False

            stack.append((val[0].left, val[1].left))
            stack.append((val[0].right, val[1].right))
        
        return True
