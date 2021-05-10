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
    
    vector<int> postorderTraversal1(TreeNode* root) 
    {
        std::stack<TreeNode*> st;
        std::vector<int> res;
        TreeNode* prev = nullptr;
        while(root || !st.empty())
        {
            if(root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                if(root->right && root->right != prev)
                {
                    prev = root;
                    root = root->right;
                }
                else
                {
                   prev = root;
                   res.push_back(root->val);
                   st.pop();
                   root = nullptr;
                }
                    
            }
        }
        return res;
    }
};
