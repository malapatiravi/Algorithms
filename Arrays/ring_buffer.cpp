
#include "ring_buffer.h"
#include "circular_buffer.h"


int main()
{
    RingBuffer<int> rb(2);
    std::cout<<"Buffer size is: "<<rb.Size()<<std::endl;
    rb.Push(10);
    std::cout<<"Buffer size is: "<<rb.Size()<<std::endl;
    rb.Push(20);
    std::cout<<"Buffer size is: "<<rb.Size()<<std::endl;
    rb.Pop();
    std::cout<<"Buffer size is: "<<rb.Size()<<std::endl;
    rb.Pop();
    std::cout<<"Buffer size is: "<<rb.Size()<<std::endl;

    // Circular_Buffer<int> cb(1);
    // std::cout<<"Is Full: "<<cb.is_full()<<std::endl;
    // std::cout<<"Is Empty: "<<cb.is_empty()<<std::endl;
    // std::cout<<"Buffer size is: "<<cb.size()<<std::endl;
    // cb.enqueue(10);
    // std::cout<<"Is Full: "<<cb.is_full()<<std::endl;
    // std::cout<<"Is Empty: "<<cb.is_empty()<<std::endl;
    // std::cout<<"Buffer size is: "<<cb.size()<<std::endl;

    // cb.enqueue(40);
    // std::cout<<"Is Full: "<<cb.is_full()<<std::endl;
    // std::cout<<"Is Empty: "<<cb.is_empty()<<std::endl;
    // std::cout<<"Buffer size is: "<<cb.size()<<std::endl;
    // cb.enqueue(45);
    // std::cout<<"Is Full: "<<cb.is_full()<<std::endl;
    // std::cout<<"Is Empty: "<<cb.is_empty()<<std::endl;
    // std::cout<<"Buffer size is: "<<cb.size()<<std::endl;
    // cb.enqueue(46);
    // std::cout<<"Is Full: "<<cb.is_full()<<std::endl;
    // std::cout<<"Is Empty: "<<cb.is_empty()<<std::endl;
    // std::cout<<"Buffer size is: "<<cb.size()<<std::endl;
    // cb.enqueue(47);
    // std::cout<<"Is Full: "<<cb.is_full()<<std::endl;
    // std::cout<<"Is Empty: "<<cb.is_empty()<<std::endl;
    // std::cout<<"Buffer size is: "<<cb.size()<<std::endl;

}