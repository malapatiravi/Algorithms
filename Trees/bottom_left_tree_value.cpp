/*
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *                  2
 *                  /\
 *                 1  3 
 *      result = 1
 * 
 */

/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        int result;
        std::queue<TreeNode *> Q;
        Q.push(root);

        while (Q.size() > 0)
        {
            size_t sz = Q.size();
            bool first = true;
            while (sz > 0)
            {
                TreeNode *node = Q.front();
                if (first)
                {
                    result = node->val;
                    first = false;
                    Q.pop();
                }
                else
                {
                    Q.pop();
                }
                if(node->left != NULL)
                {
                    Q.push(node->left);
                }
                if(node->right != NULL)
                {
                    Q.push(node->right);
                }

                sz--;
            }
        }
        return result;
    }
};