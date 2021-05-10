// Input: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
// Output: [0,2,0,0,0]
// Explanation:
// The user with ID=0 performed actions at minutes 5, 2, and 5 again. Hence, they have a UAM of 2 (minute 5 is only counted once).
// The user with ID=1 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
// Since both users have a UAM of 2, answer[2] is 2, and the remaining answer[j] values are 0.

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {

        unordered_map<int, unordered_set<int>> mp;
        std::vector<int> res;
        for(int i = 0; i < logs.size(); i++)
        {
            mp[logs[i][0]].insert(logs[i][1]);
        }

        for(auto it = mp.begin(); it != mp.end(); it++ )
        {
            ++res[it->second.size()-1];
        }
        return res;
    }
};