class Solution:
    def isBalanced(self, root):
        # For the recursion version, it gets the height from the left and right subtrees.
        # Then, it does the same for its children repeatedly. Height() is done over and over again.

        # For the optimized version, we do both at once.
        # For every node, we return True (Balanced) and Height. This propogates information upwards.
        # If at any node the height difference is > 1, we mark is as Unbalanced and exit.
        # This ensures that each subtree is processed not repeatedly over and over again. 

        # In the below solution, we have the concept of an early return if at any point -1 is returned.
        def dfs(node):
            if not node:
                return 0
            
            left = dfs(node.left)
            if left == -1:
                return -1
            
            right = dfs(node.right)
            if right == -1:
                return -1
            
            if abs(left - right) > 1:
                return -1
            
            return 1 + max(left, right)

        return dfs(root) != -1