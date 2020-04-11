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
        std::stack<TreeNode*> st;
        while(root || st.size() > 0)
        {
            if(root != NULL)
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
};