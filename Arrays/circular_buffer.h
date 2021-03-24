//===================================================================
// File: Ring Buffer.h
//
// Desc: A Circular Buffer implementation in C++.
//
// Copyright © 2021 Ravichandra Malapati. All rights reserved.
//
//===================================================================

#include <memory>

template <class T>
class Circular_Buffer
{
private:
    std::unique_ptr<T[]> buffer; // using a smart pointer is safer (and we don't
                                 // have to implement a destructor)
    size_t head = 0;             // size_t is an unsigned long
    size_t tail = 0;
    size_t max_size;
    size_t curr_size;
    T empty_item; // we will use this to clear data
public:

    // Create a new Circular_Buffer.
    Circular_Buffer<T>(size_t max_size)
        : buffer(std::unique_ptr<T[]>(new T[max_size])), max_size(max_size), curr_size(0U){};

    // Add an item to this circular buffer.
    void enqueue(T item)
    {

        // if buffer is full, throw an error
        if (is_full())
        {
            // throw std::runtime_error("buffer is full");
            dequeue();
        }

        // insert item at back of buffer
        buffer[tail] = item;

        // increment tail
        tail = (tail + 1) % max_size;
        curr_size++;
    }

    // Remove an item from this circular buffer and return it.
    T dequeue()
    {

        // if buffer is empty, throw an error
        if (is_empty())
        {
            throw std::runtime_error("buffer is empty");
        }
            

        // get item at head
        T item = buffer[head];

        // set item at head to be empty
        T empty;
        buffer[head] = empty_item;

        // move head foward
        head = (head + 1) % max_size;
        curr_size--;

        // return item
        return item;
    }

    // Return the item at the front of this circular buffer.
    T front() { return buffer[head]; }

    // Check and return true if this circular buffer is empty, and false otherwise.
    bool is_empty() { return curr_size == 0; }

    // Check and return true if circular buffer is full. 
    bool is_full()
    { 
        return curr_size == max_size;
    }

    // Return the size of this circular buffer.
    size_t size()
    {
        int t = tail-1;
        if (t < 0)
        {
            t = max_size - 1;
        }
        std::cout << "Head is: " << head << " Tail is: " << tail << " Head Val is: " << buffer[head] <<" Tail Val is: "<< buffer[t]<<std::endl;
        return curr_size;
    }
};
