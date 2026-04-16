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
        # Without last, you wouldn’t know: whether you're coming back from the left subtree or coming back from the right subtree.
        # That distinction is crucial because: After left → you still need to go right After right → you can process the node
        last = None
        depths = {}

        while stack or node:
            if node:
                stack.append(node)
                node = node.left # Keep going left until we hit a nullptr. 
            else:
                node = stack[-1] # Peek the last item in the stack. 
                if not node.right or last == node.right: # Try to go right if possible until no longer possible, or if the last processed item is the node.right. 
                    stack.pop() # “I’ve finished both left and right subtrees → now I can process this node → remove it.”
                    left = depths.get(node.left, 0) # Get left height. 
                    right = depths.get(node.right, 0) # Get right height. 

                    if abs(left - right) > 1: # Explode if we break the rule. 
                        return False
                    
                    depths[node] = 1 + max(left, right) # Otherwise, store. 
                    last = node # The last node we processed was the right child, which is correct here. 
                    node = None
                else:
                    node = node.right

        return True