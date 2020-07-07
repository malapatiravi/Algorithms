/*
How to fuse multiple slices of Pizza
Lets say we have 20 slices of pizza and we have 5 pizzas
We want to overlap each pizza slice with another pizza
Once we do that find out how many pizzas are there in each sliced angle. 
build a look up table to find out how many slices in each angle and what is the maximum length and minimum length

*/
#include <iostream>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <climits>
#include <cmath>
#include <cfenv>

class Slice
{
    public:
        float slice_start;
        float slice_end;
        float max_length;
        float max_length_1;
        float max_length_2;
};

class Pizza
{
    public:
         Slice slices_reg[40];
         int number_of_slices;
         float resolution;

};


class Solution
{

public:
    Pizza output_pizza;
    int number_of_slices;
    int output_resolution;
    uint8_t lookup_table[180];

    void FuseThePizzaSlices(Pizza pizza1, Pizza pizza2)
    {
        for(int i = 0; i < 180; i++)
        {
            lookup_table[i] = i%output_resolution;
        }
       // Initialize output pizza
       for(int slice = 0; slice < pizza1.number_of_slices; slice++)
       {
           float start = pizza1.slices_reg[slice].slice_start;
           float end = pizza1.slices_reg[slice].slice_end;
           int start_i = std::round(start);
           int end_i = std::round(end);
           uint8_t start_slice_num = lookup_table[start_i];
           uint8_t end_slice_num = lookup_table[end_i];
           output_pizza.slices_reg[start_slice_num].max_length = std::min(output_pizza.slices_reg[start_slice_num].max_length, pizza1.slices_reg[slice].max_length);
           output_pizza.slices_reg[start_slice_num].max_length_1 = std::min(output_pizza.slices_reg[start_slice_num].max_length_1, pizza1.slices_reg[slice].max_length_1);
           output_pizza.slices_reg[start_slice_num].max_length_2 = std::min(output_pizza.slices_reg[start_slice_num].max_length_2, pizza1.slices_reg[slice].max_length_2);

           output_pizza.slices_reg[end_slice_num].max_length = std::min(output_pizza.slices_reg[end_slice_num].max_length, pizza1.slices_reg[slice].max_length);
           output_pizza.slices_reg[end_slice_num].max_length_1 = std::min(output_pizza.slices_reg[end_slice_num].max_length_1, pizza1.slices_reg[slice].max_length_1);
           output_pizza.slices_reg[end_slice_num].max_length_2 = std::min(output_pizza.slices_reg[end_slice_num].max_length_2, pizza1.slices_reg[slice].max_length_2);
           
       }

       for(int slice = 0; slice < pizza2.number_of_slices; slice++)
       {
           float start = pizza2.slices_reg[slice].slice_start;
           float end = pizza2.slices_reg[slice].slice_end;
           int start_i = std::round(start);
           int end_i = std::round(end);
           uint8_t start_slice_num = lookup_table[start_i];
           uint8_t end_slice_num = lookup_table[end_i];
           output_pizza.slices_reg[start_slice_num].max_length = std::min(output_pizza.slices_reg[start_slice_num].max_length, pizza2.slices_reg[slice].max_length);
           output_pizza.slices_reg[start_slice_num].max_length_1 = std::min(output_pizza.slices_reg[start_slice_num].max_length_1, pizza2.slices_reg[slice].max_length_1);
           output_pizza.slices_reg[start_slice_num].max_length_2 = std::min(output_pizza.slices_reg[start_slice_num].max_length_2, pizza2.slices_reg[slice].max_length_2);

           output_pizza.slices_reg[end_slice_num].max_length = std::min(output_pizza.slices_reg[end_slice_num].max_length, pizza2.slices_reg[slice].max_length);
           output_pizza.slices_reg[end_slice_num].max_length_1 = std::min(output_pizza.slices_reg[end_slice_num].max_length_1, pizza2.slices_reg[slice].max_length_1);
           output_pizza.slices_reg[end_slice_num].max_length_2 = std::min(output_pizza.slices_reg[end_slice_num].max_length_2, pizza2.slices_reg[slice].max_length_2);
           
       }

    }

};
