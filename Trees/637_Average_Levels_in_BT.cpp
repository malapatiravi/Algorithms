#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
*/
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
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::queue<TreeNode *> Q;
        std::vector<double> result;
        Q.push(root);
        while (!Q.empty())
        {
            int sz = Q.size();
            std::vector<int> values;
            while (sz > 0)
            {
                root = Q.front();
                Q.pop();
                values.push_back(root->val);
                if (root->left)
                    Q.push(root->left);
                if (root->right)
                    Q.push(root->right);
                sz--;
            }
            sz = values.size();
            double value = std::accumulate(values.begin(), values.end(), 0.0)/sz;
            result.push_back(value);
        }
        return result;
    }
};