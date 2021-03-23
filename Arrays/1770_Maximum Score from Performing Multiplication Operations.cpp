#include <iostream>
#include <vector>
/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

*/
using namespace std;
class Solution
{
public:
    int dp[1001][1001] = {};
    int maxScore(vector<int> &nums, vector<int> &multipliers, int nums_start, int nums_end, int m_i)
    {
        if (m_i >= multipliers.size())
        {
            return 0;
        }
        if (dp[nums_start][m_i] == 0)
        {
            int first = 0;
            int second = 0;
            if (nums_start < nums.size() && nums_end < nums.size())
            {
                first = maxScore(nums, multipliers, nums_start + 1, nums_end, m_i + 1);
                first = first + multipliers[m_i] * nums[nums_start];
            }
            if (nums_end < nums.size() && nums_start < nums.size())
            {
                second = maxScore(nums, multipliers, nums_start, nums_end - 1, m_i + 1);
                second = second + multipliers[m_i] * nums[nums_end];
            }
            dp[nums_start][m_i] = max(first, second);
            return dp[nums_start][m_i];
        }
        else
            return dp[nums_start][m_i];
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        return maxScore(nums, multipliers, 0, nums.size() - 1, 0);
    }
};