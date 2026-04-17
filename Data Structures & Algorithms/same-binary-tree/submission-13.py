# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def IsSame(rootLeft, rootRight):
            if not rootLeft and not rootRight:
                return True 

            if not rootLeft or not rootRight:
                return False

            if rootLeft.val == rootRight.val:
                return IsSame(rootLeft.left, rootRight.left) and IsSame(rootLeft.right, rootRight.right)

            return False
        
        return IsSame(p, q)