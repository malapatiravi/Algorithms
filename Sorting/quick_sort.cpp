#include<iostream>
#include<vector>
void quickSortRecur(std::vector<int> &nums, int left, int right)
{
    if(right-left >=2)
    {
        int P1 = left;
        int P2 = right-1;
        int P = right;
        while(P1 < P2)
        {
            if(nums[P1] <= nums[P] && nums[P2] <= nums[P])
            {
                P1++;
            }
            else if(nums[P1] <= nums[P] && nums[P2] >= nums[P])
            {
                P1++;
            }
            else if(nums[P1] >= nums[P] && nums[P2] <= nums[P])
            {
                std::swap(nums[P1], nums[P2]);
                P1++;
            }
            else if(nums[P1] >= nums[P] && nums[P2] >= nums[P])
            {
                P2--;
            }
            else
            {
                //Do nothing. 
            }
        }
        std::swap(nums[P2], nums[P]);
        quickSortRecur(nums, left, P2-1);
        quickSortRecur(nums, P2, right);
    }
    else
    {
        if(nums[left] > nums[right])
        {
            std::swap(nums[left], nums[right]);
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

    quickSortRecur(data, 0, data.size() - 1);
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "==>";
    }
    std::cout << std::endl;
}