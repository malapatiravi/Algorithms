#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> post;
        if (!root)
        {
            return post;
        }
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *curr;
        while (1)
        {
            if (s.empty())
                break;
            curr = s.top();
            s.pop();
            post.push_back(curr->val);
            if (curr->left)
                s.push(curr->left);
            if (curr->right)
                s.push(curr->right);
        }
        reverse(post.begin(), post.end());
        return post;
    }
};
