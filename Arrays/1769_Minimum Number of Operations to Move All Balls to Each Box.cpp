
/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> min_moves;
        for (int i = 0; i < boxes.size(); i++)
        {
            int min_move = 0;
            int left = 0;
            while (left < i)
            {
                if (boxes[left] == '1')
                {
                    min_move += i - left;
                }
                left++;
            }

            int right = boxes.size() - 1;
            while (right > i)
            {
                if (boxes[right] == '1')
                {
                    min_move += right - i;
                }
                right--;
            }
            min_moves.push_back(min_move);
        }
        return min_moves;
    }
};
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        std::vector<int> ans(boxes.length());
        int number_of_ones = 0;
        int number_of_accum_moves = 0;
        for(int i = 0; i < boxes.length(); i++)
        {
            number_of_accum_moves = number_of_accum_moves + number_of_ones;
            ans[i] = number_of_accum_moves;
            number_of_ones = number_of_ones + boxes[i]-'0';
        }
        number_of_ones = 0;
        number_of_accum_moves = 0;
        for(int i = boxes.length()-1; i >=0; i--)
        {
            number_of_accum_moves = number_of_accum_moves + number_of_ones;
            ans[i] += number_of_accum_moves;
            number_of_ones = number_of_ones + boxes[i]-'0';
        }
        return ans;
    }
};
// class Solution
// {
// public:
//     vector<int> minOperations(string boxes)
//     {
//         int len = boxes.length();
//         vector<int> ans(len);
//         for (int i = 0, s = 0, last = 0; i < len; ++i)
//         {
//             ans[i] = last = last + s;
//             s += boxes[i] - '0';
//         }
//         for (int i = len - 1, s = 0, last = 0; i >= 0; --i)
//         {
//             ans[i] += last = last + s;
//             s += boxes[i] - '0';
//         }
//         return ans;
//     }
// };