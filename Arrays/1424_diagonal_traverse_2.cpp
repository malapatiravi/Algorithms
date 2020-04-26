#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        std::vector<int> res;
        int n_rows = nums.size();
        int n_max_cols = 0;
        for (int i = 0; i < n_rows; i++)
        {
            n_max_cols = std::max(n_max_cols, static_cast<int>(nums[i].size()));
        }
        int n_r = n_rows;
        int r = 0;
        //std::cout<<n_max_cols<<std::endl;
        while (r < n_r)
        {
            int i = r;
            int j = 0;
            //int
            while (j < n_max_cols && i >= 0)
            {
                if (j < nums[i].size())
                {
                    //std::cout<<i<<" " <<j<<" " <<nums[i][j]<<std::endl;
                    res.push_back(nums[i][j]);
                }
                else
                {
                }
                j++;
                i--;
            }
            //std::cout<<"Rows"<<std::endl;
            r++;
        }

        int n_c = n_max_cols;
        int c = 1;
        int last_row = nums.size() - 1;
        while (c < n_max_cols)
        {
            int i = last_row;
            int j = c;
            while (j < n_max_cols && i >= 0)
            {
                if (j < nums[i].size())
                {
                    //std::cout<<i<<" " <<j<<" " <<nums[i][j]<<std::endl;
                    res.push_back(nums[i][j]);
                }
                i--;
                j++;
            }
            //std::cout<<"Cols"<<std::endl;
            c++;
        }

        return res;
    }

    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<tuple<int, int, int>> tpls;
        int n_rows = nums.size();
        for (int row = 0; row < n_rows; ++row)
        {
            int n_cols = nums[row].size();
            for (int col = 0; col < n_cols; ++col)
                tpls.emplace_back(row + col, col, nums[row][col]);
        }
        sort(tpls.begin(), tpls.end());
        vector<int> arr;
        for (auto tpl : tpls)
            arr.push_back(get<2>(tpl));
        return arr;
    }
};