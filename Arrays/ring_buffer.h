#include <iostream>
#include <memory>
#define DEBUG true
template <typename T>
class RingBuffer
{
private:
    T *Q;
    int front_ptr = 0U; // for poping
    int back_ptr = -1;  // for pushing
    uint32_t max_sz = 0U;
    uint32_t curr_sz = 0U;

    bool is_max();

public:
    RingBuffer(int max_size);

    void Push(T val);
    void Pop();
    void printQ();
    int Size();
};

template <typename T>
bool RingBuffer<T>::is_max()
{
    if (curr_sz != max_sz)
    {
        return false;
    }
    return true;
}

template <typename T>
RingBuffer<T>::RingBuffer(int max_size)
{
    max_sz = max_size;
    Q = (T *)calloc(max_size, sizeof(T));
}

template <typename T>
void RingBuffer<T>::Push(T val)
{
    std::cout << "Before Pushing size is" << curr_sz << std::endl;
    if (!is_max())
    {
        if (back_ptr > front_ptr)
        {
            if (back_ptr + 1 < max_sz)
            {
                Q[back_ptr + 1] = val;
                back_ptr++;
                curr_sz++;
            }
            else
            {
                back_ptr = 0;
                Q[back_ptr] = val;
                curr_sz++;
            }
        }
        else if (back_ptr <= front_ptr)
        {
            Q[back_ptr + 1] = val;
            back_ptr++;
            curr_sz++;
        }
    }
    else
    {
        Pop();
        Push(val);
    }
    std::cout << "After Pushing size is" << curr_sz << std::endl;
}

template <typename T>
void RingBuffer<T>::Pop()
{
    if (curr_sz > 0)
    {
        if (front_ptr < back_ptr)
        {
            std::cout << "Popping " << Q[front_ptr] << std::endl;
            front_ptr++;
            curr_sz--;
        }
        else if (front_ptr > back_ptr)
        {
            if (front_ptr + 1 < max_sz - 1)
            {
                std::cout << "Popping " << Q[front_ptr] << std::endl;
                front_ptr++;
                curr_sz--;
            }
            else
            {
                std::cout << "Popping " << Q[front_ptr] << std::endl;
                front_ptr = 0;
                curr_sz--;
            }
        }
    }
}

template <typename T>
void RingBuffer<T>::printQ()
{
    if (curr_sz > 0)
    {
        if (front_ptr < back_ptr)
        {
            for (int i = front_ptr; i <= back_ptr; i++)
            {
                std::cout << Q[i] << ", ";
            }
            std::cout << std::endl;
        }
        else
        {
            for (int i = front_ptr; i < max_sz; i++)
            {
                std::cout << Q[i] << ", ";
            }
            for (int i = 0; i <= back_ptr; i++)
            {
                std::cout << Q[i] << ", ";
            }
            std::cout << std::endl;
        }
    }
}

template <typename T>
int RingBuffer<T>::Size()
{
    return curr_sz;
}
