#include <iostream>
#include <vector>
void quickSortRecur(std::vector<int> &nums, int start, int end)
{
    if (end - start >= 2)
    {
        int P1 = start;
        int P2 = end - 1;
        int P = end;

        while (P1 < P2)
        {
            /*Handle all gour cases*/
            if (nums[P1] <= nums[P] && nums[P2] <= nums[P])
            {
                P1++;
            }
            else if (nums[P1] >= nums[P] && nums[P2] <= nums[P])
            {
                std::swap(nums[P1], nums[P2]);
                P1++;
            }
            else if (nums[P1] <= nums[P] && nums[P2] >= nums[P])
            {
                P1++;
            }
            else if (nums[P1] >= nums[P] && nums[P2] >= nums[P])
            {
                P2--;
            }
            else
            {
                /* code */
            }
        }
        if (nums[P2] > nums[P])
            std::swap(nums[P2], nums[P]);

        quickSortRecur(nums, start, P2);
        quickSortRecur(nums, P2 + 1, end);
    }
    else
    {
        /*Handle length of two*/
        if (end - start == 1)
        {
            if (nums[start] > nums[end])
            {
                std::swap(nums[start], nums[end]);
            }
            else
            {
                // do nothing
            }
        }
        else
        {
            /* Do nothing*/
        }
        return;
    }
}


int main()
{
    std::vector<int> data;
    for (int i = 100; i > 0; i--)
    {
        data.push_back(i);
    }
    for (int i = 50; i > 0; i--)
    {
        data.push_back(i);
    }

    quickSort(data, 0, data.size() - 1);
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "==>";
    }
    std::cout << std::endl;
}