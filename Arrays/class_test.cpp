#include <iostream>

class Test
{
    public:
    int fun1()
    {
        return 20;
    }
    int fun2()
    {
        return 30;
    }
    // private:
        uint8_t b_;
        bool e_;
        uint16_t c_;
        float a_;
        uint32_t d_;
};

int main()
{
    std::clog<<sizeof(Test)<<std::endl;
    Test t;
    std::clog<<" A "<<&t.a_<<" \n B "<<(void*)&t.b_<<" \n C "<<&t.c_<<"\n D "<<&t.d_<<"\n E "<<&t.e_<<std::endl;
}