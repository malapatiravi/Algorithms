
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        std::map<int, int> mp;
        std::vector<int> res;
        for (int i : nums)
        {
            mp[i]++;
        }

        auto compare = [](std::pair<int, int> one, std::pair<int, int> two) -> bool {
            return one.second > two.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<pair<int, int>>, decltype(compare)> pq(compare);

        for (auto it = mp.begin(); it != mp.end(); it++)
        {

            pq.push(pair<int, int>(it->first, it->second));
            if (pq.size() > k)
            {

                pq.pop();
            }
        }
        int siz = pq.size();
        while (siz > 0)
        {
            res.push_back(pq.top().first);
            pq.pop();
            siz--;
        }
        return res;
    }
};

int main()
{
    //priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    auto compare1 = [](std::pair<int, int> one, std::pair<int, int> two) -> bool {
        return one.first < two.first;
    };

    auto sortRuleLambda = [](std::pair<int, int> const &s1, std::pair<int, int> const &s2) -> bool {
        return s1.first < s2.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare1)> pq(compare1);

    for (int i = 0; i < 5; i++)
    {
        pq.push(pair<int, int>(i, 1));
    }
    for (int i = 5; i < 10; i++)
    {
        pq.push(pair<int, int>(i, 0));
    }
    int siz = pq.size();
    while (siz > 0)
    {
        pair<int, int> p = pq.top();
        pq.pop();
        std::cout << p.first << std::endl;
        siz--;
    }

    std::vector<int> nums;
    nums.push_back(1);
    Solution sol;
    std::vector<int> res = sol.topKFrequent(nums, 1);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
}