# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # If any subtree is unbalanced, propagate -1 up immedietely. 
        def traverse(node):
            if not node: 
                return 0

            left = traverse(node.left)
            if left == -1:
                return -1

            right = traverse(node.right)
            if right == -1:
                return -1
            
            if abs(left - right) > 1:
                return -1

            # Key here. Height is the number of edges on the longest path from a node down to a leaf. 
            return 1 + max(left, right)

        return traverse(root) != -1
