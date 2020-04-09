#include <iostream>
#include <vector>
#include <algorithm>
class MergeSort
{
public:
    void TopDownMergeSort(int left, int right, std::vector<int> &data, int max_element);
    void TopDownMerge(int left, int middle, int right, std::vector<int> &data, int max_element);
    void MergeStart(int left, int right, std::vector<int> &data);
};

void MergeSort::TopDownMergeSort(int left, int right, std::vector<int> &data, int max_element)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        TopDownMergeSort(left, middle, data, max_element);
        TopDownMergeSort(middle + 1, right, data, max_element);
        TopDownMerge(left, middle, right, data, max_element);
    }
}

void MergeSort::TopDownMerge(int left, int middle, int right, std::vector<int> &data, int max_element)
{
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (data[i] % max_element <= data[j] % max_element)
        {
            data[k] = data[k] + (data[i]% max_element)*max_element;
            k++;
            i++;
        }
        else
        {
            data[k] = data[k] + (data[j] % max_element)*max_element;
            k++;
            j++;
        }
        
    }

    while (i <= middle)
    {
        data[k] = data[k]+(data[i] % max_element)*max_element;
        k++;
        i++;
    }

    while (j <= right)
    {
        data[k] = data[k] + (data[j] % max_element)*max_element;
        k++;
        j++;
    }
    for(int i = left; i <= right; i++)
    {
        data[i] = data[i]/max_element;
    }
}

void MergeSort::MergeStart(int left, int right, std::vector<int> &data)
{
    int max_element = *std::max_element(data.begin(),data.end() )+1;
    TopDownMergeSort(left, right, data, max_element);
}


int main()
{
    std::vector<int> data;
    for(int i = 0; i < 100; i++)
    {
        data.push_back(100-i);
    }
    MergeSort mergeS;
    mergeS.MergeStart(0, data.size()-1, data);
    for(int i = 0; i < data.size(); i++)
    {
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}