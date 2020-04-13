#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        std::stack<TreeNode *> st;
        while (root || st.size() > 0)
        {
            if (root != NULL)
            {
                result.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return result;
    }

    std::vector<int> preorderTraversal1(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode *> st;
        if (!root)
            return res;
        while (root || !st.empty())
        {
            if (root)
            {
                res.push_back(root->val);
                if (root->right)
                {
                    st.push(root->right);
                }
                if (root->left)
                {
                    st.push(root->left);
                }
                root = NULL;
            }
            else
            {
                root = st.top();
                st.pop();
            }
        }
        return res;
    }
};