#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int first_score = 0;
        int second_score = 0;
        int max_score = 0;
        if (s.size() >= 2)
        {
            if (s[0] == '0')
            {
                first_score = 1;
            }
            int i = 1;
            while (i < s.size())
            {
                if (s[i] == '1')
                {
                    second_score = second_score + 1;
                }
                i++;
            }
            max_score = std::max(max_score, first_score + second_score);

            int m = 1;
            while (m < s.size() - 1)
            {
                if (s[m] == '0')
                {
                    first_score = first_score + 1;
                }
                else
                {
                    second_score = second_score - 1;
                }
                max_score = std::max(max_score, first_score + second_score);
                m++;
            }
        }
        return max_score;
    }
};