/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<std::pair<TreeNode*, TreeNode*>> bfsQueue;
        bfsQueue.push({ p, q });

        while (!bfsQueue.empty())
        {
            std::pair<TreeNode*, TreeNode*> queueFront = bfsQueue.front();
            bfsQueue.pop();
            if (queueFront.first == nullptr && queueFront.second == nullptr)
            {
                continue;
            }

            if (queueFront.first && queueFront.second && queueFront.first->val == queueFront.second->val)
            {
                bfsQueue.push({ queueFront.first->left, queueFront.second->left });
                bfsQueue.push({ queueFront.first->right, queueFront.second->right });
            }
            else
            {
                return false;
            }
        }

        return true;
        /*
        std::stack<std::pair<TreeNode*, TreeNode*>> dfsStack;
        dfsStack.push({ p, q });

        while (!dfsStack.empty())
        {
            std::pair<TreeNode*, TreeNode*> treePair = dfsStack.top();
            dfsStack.pop();

            // Continue if both are nullptrs. This is considered "correct".
            if (!treePair.first && !treePair.second) continue;
            // Push if the nodes are valid.
            if (treePair.first && treePair.second && treePair.first->val == treePair.second->val)
            {
                dfsStack.push({ treePair.first->right, treePair.second->right });
                dfsStack.push({ treePair.first->left, treePair.second->left });
            }
            else
            {
                return false;
            }
        }

        return true;
        */
        /*
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        
        // If either is nullptr, they cannot be the same.
        if (p && q && p->val == q->val)
        {
            bool isLeftTreeSame = isSameTree(p->left, q->left);
            bool isRightTreeSame = isSameTree(p->right, q->right);
            return isLeftTreeSame && isRightTreeSame;
        }

        return false;
        */
    }
};
