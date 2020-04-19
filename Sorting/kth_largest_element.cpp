
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int partition1(std::vector<int> &nums, int left, int right)
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
            if (l < r)
            {
                std::swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        // if (left < r)
        // {
        //     //partition1(nums, left, r);
        //     return r;
        // }
        // if (right > l)
        // {
        //     //partition1(nums, l, right);
        //     return l;
        // }
        //std::cout<<"returning "<<r<<std::endl;
        return r;
    }
    int partition(vector<int> &nums, int low, int high)
    {
        if (high - low >= 1)
        {
            int l = low;
            int p = high;
            int r = high - 1;

            while (l < r)
            {
                if (nums[l] <= nums[p] && nums[r] <= nums[p])
                {
                    l++;
                }
                else if (nums[l] <= nums[p] && nums[r] >= nums[p])
                {
                    l++;
                }
                else if (nums[l] >= nums[p] && nums[r] <= nums[p])
                {
                    //std::cout<<"Here "<<nums[l]<<" "<<nums[r]<<std::endl;;
                    swap(nums[l], nums[r]);
                    l++;
                }
                else if (nums[l] >= nums[p] && nums[r] >= nums[p])
                {
                    r--;
                }
                else
                {
                    //Do nothing
                }
            }
            if (nums[r] > nums[p])
            {
                swap(nums[r], nums[p]);
                //std::cout << "Sending " << r << std::endl;
                return r;
            }
            else
            {
                //std::cout << "Sending No swap " << r << std::endl;
                return p;
            }
        }
        else
        {
            if (nums[low] > nums[high])
            {
                swap(nums[low], nums[high]);
                return high;
            }
            return low;
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        if (k < nums.size() && nums.size() > 1)
        {
            k = nums.size() - k;
            int l = 0;
            int r = nums.size() - 1;
            while (r-l > 1)
            {
                int pi = partition(nums, l, r);

                //std::cout<<pi<<std::endl;
                if (k == pi)
                {
                    return nums[pi];
                }
                else if (pi < k)
                {
                    l = pi;
                   
                }
                else if (pi > k)
                {
                    r = pi-1;
                    
                }
                else
                {
                    /* code */
                }
            }
            return nums[r];
        }
        if (nums.size() == 1)
            return nums[0];
        return -1;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{3,2,3,1,2,4,5,5,6};
    int k = 4;
    std::cout << sol.findKthLargest(nums, k);
}