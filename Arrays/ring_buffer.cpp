
#include "ring_buffer.h"



int main()
{
    RingBuffer<int> rb(10);
    rb.Push(10);
    rb.Push(9);
    rb.Push(8);
    rb.Push(7);
    rb.Push(6);
    rb.Push(5);
    rb.Push(4);
    rb.Push(3);
    rb.Push(2);
    rb.Push(1);
    rb.printQ();
    rb.Push(-1);
    rb.Push(-2);
    rb.Push(-3);
    rb.printQ();
    rb.Pop();
    rb.Pop();
    rb.Pop();
    rb.Pop();
    rb.printQ();
}