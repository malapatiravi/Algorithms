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
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::stack<TreeNode *> st;
        st.push(root);
        std::vector<int> res;
        if (!root)
        {
            return res;
        }
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            if (root->left)
                st.push(root->left);
            if (root->right)
                st.push(root->right);
            res.push_back(root->val);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
