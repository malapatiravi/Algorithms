
// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution 
{
public:
    int r_[4] = {-1, 0, 1, 0};
    int c_[4] = {0, -1, 0, 1};

    bool isValid(int r, int c, int rr, int cc)
    {
        if(rr >= 0 && rr < r && cc >= 0 && cc < c)
        {
            return true;
        }
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        // Fill all land cells with -1
        // Put all the water cells in queue
        int rows = isWater.size();
        int columns = isWater[0].size();
        int max_height = -1;
        std::queue<std::pair<int,int>> Q;
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                if(isWater[r][c] != 1)
                {
                    isWater[r][c] = -1;
                }
                else
                {
                    isWater[r][c] = 0;
                    Q.push(std::make_pair(r, c));
                }
            }
        }
        
        while(Q.size() > 0)
        {   
            int len = Q.size();
            while(len > 0)
            {
                std::pair<int, int> input = Q.front();
                Q.pop();
                len--;
                int r = input.first; int c = input.second;
                std::cout<<r<<c<<std::endl;
                //1. Check all four sides and increment by 
                // a. Check top.
                for(int i = 0; i < 4; i++)
                {
                    int r_t = r + r_[i];
                    int c_t = c + c_[i];
                    if(isValid(rows, columns, r_t, c_t))
                    {
                        if(isWater[r_t][c_t] == -1)
                        {
                            isWater[r_t][c_t] = isWater[r][c] + 1;
                            Q.push(std::make_pair(r_t, c_t));
                        }
                    }
                }
            }
        }
        return isWater;
    }
};