#include <vector>
#include <iostream>
class Solution
{
public:
    int arrayNesting(std::vector<int> &nums)
    {
        std::vector<bool> visited(nums.size(), false);
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                int start = nums[i];
                int count = 0;
                do
                {
                    /* code */
                    start = nums[start];
                    count++;
                    visited[start] = true;

                } while (start != nums[i]);
                res = std::max(res, count);
                
            }
        }
        return res;
    }
};
int main()
{
    
}