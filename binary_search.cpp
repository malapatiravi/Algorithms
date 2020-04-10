#include <iostream>
#include <vector>

int binary_search(std::vector<int> &nums, int left, int right, int find_num)
{
    int middle = left + (right - left) / 2;
    if (right - left <= 1)
    {
        if (nums[right] == find_num)
            return right;
        if (nums[left] == find_num)
            return left;
        return -1;
    }
    if (nums[middle] > find_num)
    {
        return binary_search(nums, left, middle, find_num);
    }
    else if (nums[middle] < find_num)
    {
        /* code */
        return binary_search(nums, middle + 1, right, find_num);
    }
    else if (nums[middle] == find_num)
    {
        return middle;
    }
    else
    {
        //Do nothing
        return 0;
    }
}

int main()
{
    std::vector<int> nums;
    int k = 0;
    for (int i = 0; i < 200; i = i + 2)
    {
        nums.push_back(i);
        std::cout<<k<<"-->"<<nums[k]<<std::endl;
        k++;
    }
    std::cout << binary_search(nums, 0, nums.size() - 1, 101) << std::endl;
}