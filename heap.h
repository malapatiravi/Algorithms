

#include <iostream>
#define MIN_HEAP false
#define MAX_HEAP true

template <typename KeyType, typename StructType, int Size>
class Heap
{
public:
    Heap(bool _heap_type);
    ~Heap();
    void Clear();
    void Push(StructType data);
    StructType Pop();
    StructType Peek();
    int GetSize();
    void print();

private:
    StructType buffers_[Size]; // Initializes the buffers with size
    int left(int it);          // Declaration of function for left function
    int right(int it);         // Declaration of function for right function
    int parent(int it);        // Declaration of function for parent function.
    void swap(int it1, int it2);
    void Heapify(int it);      // Min Heapify
    void HeapifyRecur(int it); // Min Heapify Recursive
    // void MaxHeapify(int it);      // Max Heapify
    // void MaxHeapifyRecur(int it); // Max Heapify Recursive
    bool Compare(KeyType key1, KeyType key2);
    int heapSize;
    bool heap_type;
    int maxSize = Size;
};
template <typename KeyType, typename StructType, int Size>
bool Heap<KeyType, StructType, Size>::Compare(KeyType key1, KeyType key2)
{
    if (heap_type == MIN_HEAP)
    {
        if (key1 < key2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (heap_type == MAX_HEAP)
    {
        if (key1 > key2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
template <typename KeyType, typename StructType, int Size>
void Heap<KeyType, StructType, Size>::Push(StructType data)
{
    if (heapSize >= maxSize)
    {
        buffers_[maxSize - 1] = data;

        //Log error
    }

    heapSize++;
    int it = heapSize - 1;
    buffers_[it] = data;

    while (it != 0 && Compare(buffers_[it].first, buffers_[parent(it)].first))
    {
        swap(parent(it), it);
        it = parent(it);
    }
}

template <typename KeyType, typename StructType, int Size>
StructType Heap<KeyType, StructType, Size>::Pop()
{
    if (heapSize != 0)
    {
        StructType res = buffers_[0];
        int it = 0;
        int last = heapSize - 1;
        heapSize--;
        swap(it, last);
        Heapify(0);
        //HeapifyRecur(0);
        return res;
    }
    else
    {
        return buffers_[0];
    }
}
template <typename KeyType, typename StructType, int Size>
void Heap<KeyType, StructType, Size>::print()
{
    for (int i = 0; i < heapSize; i++)
    {
        std::cout << buffers_[i].first << "==> " << buffers_[i].second << "|||";
    }
    std::cout << std::endl;
}
template <typename KeyType, typename StructType, int Size>
Heap<KeyType, StructType, Size>::Heap(bool _heap_type)
{
    heapSize = 0;
    heap_type = _heap_type;
}

template <typename KeyType, typename StructType, int Size>
Heap<KeyType, StructType, Size>::~Heap()
{
}

template <typename KeyType, typename StructType, int Size>
int Heap<KeyType, StructType, Size>::left(int it)
{
    return (2 * it + 1);
}

template <typename KeyType, typename StructType, int Size>
int Heap<KeyType, StructType, Size>::right(int it)
{
    return (2 * it + 2);
}

template <typename KeyType, typename StructType, int Size>
int Heap<KeyType, StructType, Size>::parent(int it)
{
    return (it - 1) / 2;
}

template <typename KeyType, typename StructType, int Size>
void Heap<KeyType, StructType, Size>::swap(int it1, int it2)
{
    StructType temp = buffers_[it1];
    buffers_[it1] = buffers_[it2];
    buffers_[it2] = temp;
}

template <typename KeyType, typename StructType, int Size>
void Heap<KeyType, StructType, Size>::Heapify(int it)
{
    int left_i = left(it);   // Left iterator
    int right_i = right(it); // Right iterator
    int smallest = it;       //smallest iterator
    bool initial = true;     // initial stage
    while (initial == true || smallest != it)
    {
        initial = false;
        it = smallest;
        left_i = left(it);
        right_i = right(it);

        if ((left_i < heapSize) && Compare(buffers_[left_i].first, buffers_[smallest].first))
        {
            smallest = left_i;
        }
        if ((right_i < heapSize) && Compare(buffers_[right_i].first, buffers_[smallest].first))
        {
            smallest = right_i;
        }

        if (smallest != it)
        {
            swap(smallest, it);
        }
    }
}

template <typename KeyType, typename StructType, int Size>
void Heap<KeyType, StructType, Size>::HeapifyRecur(int it)
{
    int left_i = left(it);   // Left iterator
    int right_i = right(it); // Right iterator
    int smallest = it;       //smallest iterator

    if ((left_i < heapSize) && Compare(buffers_[left_i].first, buffers_[smallest].first))
    {
        smallest = left_i;
    }
    if ((right_i < heapSize) && Compare(buffers_[right_i].first, buffers_[smallest].first))
    {
        smallest = right_i;
    }

    if (smallest != it)
    {
        swap(smallest, it);
        HeapifyRecur(smallest);
    }
}

template <typename KeyType, typename StructType, int Size>
StructType Heap<KeyType, StructType, Size>::Peek()
{
    return buffers_[0];
}

template <typename KeyType, typename StructType, int Size>
int Heap<KeyType, StructType, Size>::GetSize()
{
    return heapSize;
}
// template <typename KeyType, typename StructType, int Size>
// void Heap<KeyType, StructType, Size>::MaxHeapify(int it)
// {
//     int left_i = left(it);
//     int right_i = right(it);
//     int largest = it;
//     bool initial = true;
//     while (initial == true || largest != it)
//     {
//         initial = false;
//         it = largest;
//         left_i = left(it);
//         right_i = right(it);

//         if ((left_i < heapSize) && Compare(buffers_[left_i].first , buffers_[largest].first))
//         {
//             largest = left_i;
//         }
//         if ((right_i < heapSize) && Compare(buffers_[right_i].first , buffers_[largest].first))
//         {
//             largest = right_i;
//         }
//         if (largest != it)
//         {
//             swap(largest, it);
//         }
//     }
// }

// template <typename KeyType, typename StructType, int Size>
// void Heap<KeyType, StructType, Size>::MaxHeapifyRecur(int it)
// {
//     int left_i = left(it);
//     int right_i = right(it);
//     int largest = it;

//     if ((left_i < heapSize) && Compare(buffers_[left_i].first , buffers_[largest].first))
//     {
//         largest = left_i;
//     }

//     if ((right_i < heapSize) && Compare(buffers_[right_i].first , buffers_[largest].first))
//     {
//         largest = right_i;
//     }

//     if (largest != it)
//     {
//         swap(largest, it);
//         MaxHeapifyRecur(largest);
//     }
// }

