//===================================================================
// File: ring_buffer.h
//
// Desc: A Ring Buffer implementation in C++ with fixed size.
//
// Copyright © 2021 Ravichandra Malapati. All rights reserved.
//
//===================================================================

#include <iostream>
#include <memory>
#define DEBUG true
template <typename T>
class RingBuffer
{
private:
    T *Q;
    uint32_t front_ptr = 0U; // for poping
    uint32_t back_ptr = 0U;       // for pushing
    uint32_t max_sz = 0U;
    uint32_t curr_sz = 0U;

    bool is_full();
    bool is_empty();

public:
    RingBuffer(int max_size);
    ~RingBuffer();
    void Push(T val);
    T Pop();
    void printQ();
    int Size();
};

template <typename T>
RingBuffer<T>::RingBuffer(int max_size)
{
    max_sz = max_size;
    Q = (T *)malloc(max_size * sizeof(T));
}

template <typename T>
RingBuffer<T>::~RingBuffer()
{
    free(Q);
}

template <typename T>
bool RingBuffer<T>::is_full()
{
    return max_sz == curr_sz;
}

template <typename T>
bool RingBuffer<T>::is_empty()
{
    return curr_sz == 0U;
}

template <typename T>
void RingBuffer<T>::Push(T val)
{
    std::cout << "Pushing " << val << std::endl;
    if (is_full())
    {
        Pop();
    }

    // std::cout << Q[back_ptr] << " " << back_ptr << std::endl;
    Q[back_ptr] = val;
    back_ptr = (back_ptr + 1) % max_sz;
    curr_sz++;
}

template <typename T>
T RingBuffer<T>::Pop()
{
    std::cout << "Popping " << std::endl;
    if (is_empty())
    {
        T val;
        return val;
    }
    else
    {
        T val = Q[front_ptr];
        front_ptr = (front_ptr + 1) % max_sz;
        curr_sz--;
        return val;
    }
}

template <typename T>
void RingBuffer<T>::printQ()
{
    int t = back_ptr - 1;
    if (t < 0)
    {
        t = max_sz - 1;
    }
    // needs modificaiton refer to Size
    std::cout << Q[front_ptr] << "==>" << Q[t] << std::endl;
}

template <typename T>
int RingBuffer<T>::Size()
{
    int t = back_ptr - 1;
    if (t < 0)
    {
        t = max_sz - 1;
    }
    std::cout << "Head is: " << front_ptr << " Tail is: " << back_ptr << " Head Val is: " << Q[front_ptr] << " Tail Val is: " << Q[t] << std::endl;
    return curr_sz;
}
