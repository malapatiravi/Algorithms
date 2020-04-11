
/*Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//vector<vector<int>> v(10, vector<int>(10,1));
    vector<vector<int>> generateMatrix(int n) {
        int k = n*n;
        vector<vector<int>> res(n,vector<int>(n, 0));
        int row_start = 0;
        int col_end = n;
        int row_end = n;
        int col_start = 0;
        int start = 1;
        int end = n*n;
        while(row_start < row_end && col_start < col_end)
        {
            //Print first row
            for(int i = col_start; i < col_end; i++)
            {
                res[row_start][i] = start;
                start++;
            }
            row_start++;

            //print column
            for(int i = row_start; i < row_end; i++)
            {
                res[i][col_end-1] = start;
                start++;
            }
            col_end--;

            //print row
            for(int i = col_end-1; i >= col_start; i--)
            {
                res[row_end-1][i] = start;
                start++;
            }
            row_end--;

            // print col
            for(int i = row_end-1; i >= row_start; i--)
            {
                res[i][col_start] = start;
                start++;
            }
            col_start++;
        }

    return res;
    }
};

int main()
{
    Solution sol;
    sol.generateMatrix(5);
}