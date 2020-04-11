#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>


void merge(std::vector<int> &nums, int left, int mid, int midp1, int right)
{
    int Left[mid - left + 1];
    int Right[right - mid];
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::memcpy(Left, &nums[left], n1 * sizeof(int));
    std::memcpy(Right, &nums[mid + 1], n2 * sizeof(int));

    int l = 0;
    int r = 0;
    int k = left;
    while (l < n1 && r < n2)
    {
        if (Left[l] <= Right[r])
        {
            nums[k] = Left[l];
            k++;
            l++;
        }
        else if (Left[l] > Right[r])
        {
            nums[k] = Right[r];
            k++;
            r++;
        }
        else
        {
            //Should not ome here log the error
        }
    }
    while (l < n1)
    {
        nums[k] = Left[l];
        l++;
        k++;
    }
    while (r < n2)
    {
        nums[k] = Right[r];
        r++;
        k++;
    }
    return;
}


void partition(std::vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        partition(nums, left, mid);
        partition(nums, mid + 1, right);
        merge(nums, left, mid, mid + 1, right);
        return;
    }
    else
    {
        return;
    }
}

int main()
{
    std::vector<int> data;
    for (int i = 0; i < 100; i++)
    {
        data.push_back(100 - i);
    }
    partition(data, 0, data.size() - 1);
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
}