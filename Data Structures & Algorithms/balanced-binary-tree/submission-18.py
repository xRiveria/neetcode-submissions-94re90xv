# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        stack = []
        node = root
        last = None
        depths = {}

        while stack or node:
            if node:
                stack.append(node)
                node = node.left # Keep going left until we hit a nullptr. 
            else:
                node = stack[-1] # Grab the last item in the stack. 
                if not node.right or last == node.right: # Try to go right if possible until no longer possible, or if the last processed item is the node.right. 
                    stack.pop() 
                    left = depths.get(node.left, 0) # Get left height. 
                    right = depths.get(node.right, 0) # Get right height. 

                    if abs(left - right) > 1: # Explode if we break the rule. 
                        return False
                    
                    depths[node] = 1 + max(left, right) # Otherwise, store. 
                    last = node
                    node = None
                else:
                    node = node.right

        return True