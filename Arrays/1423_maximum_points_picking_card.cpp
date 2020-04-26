#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int max_scoreHelper(vector<int> &cardPoints, int start, int end, int k)
    {
        int max_score = 0;
        if (k == end - start + 1)
        {
            for (int i = start; i <= end; i++)
            {
                max_score = max_score + cardPoints[i];
            }
            return max_score;
        }
        if (k > 0)
        {
            int max_first = max_scoreHelper(cardPoints, start, end - 1, k - 1);
            int max_second = max_scoreHelper(cardPoints, start + 1, end, k - 1);
            if (cardPoints[start] + max_second > cardPoints[end] + max_first)
            {
                max_score = cardPoints[start] + max_second;
            }
            else
            {
                max_score = cardPoints[end] + max_first;
            }
        }
        return max_score;
    }

    int maxScore2(vector<int> &cardPoints, int k)
    {
        int max_score = 0;
        int start = 0;
        int end = cardPoints.size() - 1;
        if (k == cardPoints.size())
        {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        max_score = max_scoreHelper(cardPoints, start, end, k);
        return max_score;
    }

    int maxScore1(vector<int> &a, int k)
    {
        vector<int> p = {0}, s = {0};
        partial_sum(a.begin(), a.end(), back_inserter(p));
        partial_sum(a.rbegin(), a.rend(), back_inserter(s));
        reverse(s.begin(), s.end());
        int n = a.size();
        int ans = 0;
        for (int l = 0, r = n - k; r <= n; ++l, ++r)
            ans = max(ans, p[l] + s[r]);
        return ans;
    }

    int maxScore(vector<int> &cardPoints, int k)
    {
        int max_score;
        int n = cardPoints.size();
        int left;
        int right;
        for(int i = 0; i < k; i++)
        {
            left = left + cardPoints[i];
        }
        max_score = left;
        
        for(int i = 0; i < k; i++)
        {
            left = left - cardPoints[k - i - 1];
            right = right + cardPoints[n - i - 1];
            max_score = max(max_score, left+right);
        }
    }
};