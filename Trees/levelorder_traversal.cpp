#include <iostream>
#include <vector>
#include <queue>

//Definition for a binary tree node.
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
    std::vector<int> levelorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        std::queue<TreeNode *> Q;
        Q.push(root);
        while (Q.size() >= 0)
        {
            int sz = Q.size();
            while (sz > 0)
            {
                root = Q.front();
                Q.pop();
                result.push_back(root->val);
                if (root->left)
                    Q.push(root->left);
                if (root->right)
                    Q.push(root->right);

                sz--;
            }
        }
        return result;
    }
};