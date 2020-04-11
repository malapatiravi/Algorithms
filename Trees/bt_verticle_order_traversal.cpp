/*Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, 
we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
*/
/*                          3
*                          / \
*                         9   20
*                            /  \
*                           15   7                            
*       Answer [[9],[3,15],[20],[7]]
*
*
*
*
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
/**
 * Definition for a binary tree node.
 * */

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
    std::vector<std::vector<int>> verticalTraversal(TreeNode *root)
    {
        /*to do vericle order traversal the following steps are followed
        Step 1. Assigne the horizantal distance to each node and maintain it in the has table.*/
        /*Create a queue to store the node address and the distance for that node*/
        std::vector<std::vector<int>> res;
        std::queue<std::pair<TreeNode *, int>> Q;
        std::map<int, std::vector<int>> hash_map;
        TreeNode *r = root;
        Q.push(std::pair(root, 0));
        size_t sz = Q.size();
        while (Q.size() != 0U)
        {
            size_t sz = Q.size();
            /*Level map to store the distance and the vector of nodes that are in the level at distance*/
            std::map<int, std::vector<int>> level_map;
            while (sz > 0)
            {
                std::pair<TreeNode *, int> p = Q.front();
                level_map[p.second].push_back(p.first->val);
                Q.pop();
                if (p.first->left != NULL)
                {
                    Q.push(std::pair(p.first->left, p.second - 1));
                }
                if (p.first->right != NULL)
                {
                    Q.push(std::pair(p.first->right, p.second + 1));
                }
                sz--;
            }
            for(auto it = level_map.begin(); it != level_map.end(); it++)
            {
                /*sort the level map*/
                std::sort(it->second.begin(), it->second.end());
                for(auto vec_it = it->second.begin(); vec_it != it->second.end(); vec_it++)
                {
                    hash_map[it->first].push_back(*vec_it);
                }
            }
        }

        for (auto it = hash_map.begin(); it != hash_map.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};