#include <iostream>
#include <vector>
void quickSortRecur(std::vector<int> &nums, int left, int right)
{
    if (right - left >= 2)
    {
        int P1 = left;
        int P2 = right - 1;
        int P = right;
        while (P1 < P2)
        {
            if (nums[P1] <= nums[P] && nums[P2] <= nums[P])
            {
                P1++;
            }
            else if (nums[P1] <= nums[P] && nums[P2] >= nums[P])
            {
                P1++;
            }
            else if (nums[P1] >= nums[P] && nums[P2] <= nums[P])
            {
                std::swap(nums[P1], nums[P2]);
                P1++;
            }
            else if (nums[P1] >= nums[P] && nums[P2] >= nums[P])
            {
                P2--;
            }
            else
            {
                //Do nothing.
            }
        }
        if (nums[P2] > nums[P])
        {
            std::swap(nums[P2], nums[P]);
            quickSortRecur(nums, left, P2);
            quickSortRecur(nums, P2 + 1, right);
        }
        else
        {
            quickSortRecur(nums, left, P2);
            quickSortRecur(nums, P2 + 1, right);
        }
    }
    else if (right - left > 0)
    {
        if (nums[left] > nums[right])
        {
            std::swap(nums[left], nums[right]);
        }
        return;
    }
    else
    {
        return;
    }
}

void QuickSort(std::vector<int> &nums, int left, int right)
{
    int piv_ind = left + (right - left) / 2;
    int piv_val = nums[piv_ind];
    int l = left, r = right;
    while (l < r)
    {
        while (nums[l] < piv_val)
        {
            l++;
        }
        while (nums[r] > piv_val)
        {
            r--;
        }
        if (l <= r)
        {
            std::swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    if (left < r)
    {
        QuickSort(nums, left, r);
    }
    if (right > l)
    {
        QuickSort(nums, l, right);
    }
}

// int main()
// {
//     std::vector<int> data;
//     for (int i = 100; i > 0; i--)
//     {
//         data.push_back(i);
//     }
//     // for (int i = 50; i > 0; i--)
//     // {
//     //     data.push_back(i);
//     // }
//     data.push_back(10);
//     data.push_back(9);
//     data.push_back(8);
//     data.push_back(7);
//     data.push_back(6);
//     quickSortRecur(data, 0, data.size() - 1);
//     for (int i = 0; i < data.size(); i++)
//     {
//         std::cout << data[i] << "==>";
//     }
//     std::cout << std::endl;
// }

int main()
{
    std::vector<int> nums;
    for (int i = 100; i > 0; i--)
    {
        nums.push_back(i);
    }
    QuickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << "-->";
    }
    std::cout << std::endl;
}