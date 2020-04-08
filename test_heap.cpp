#include "heap.h"
int main()
{
    Heap<float, std::pair<float, int>, 100> heap(false);
    heap.Push(std::pair<float, int>(20.0, 100));
    for (int i = 0; i < 50; i++)
    {
        heap.Push(std::pair<float, int>(i, i));
    }
    std::cout << heap.GetSize() << std::endl;
    heap.print();
    for (int i = 0; i < 10; i++)
    {
        std::cout << heap.Pop().first << std::endl;
    }
    heap.print();
    for (int i = 0; i < 15; i++)
    {
        heap.Push(std::pair<float, int>(50 + i, i));
        heap.Push(std::pair<float, int>(i, i));
    }
    heap.print();

    while (heap.GetSize() != 0)
    {
        std::cout << heap.Pop().first << std::endl;
    }
}