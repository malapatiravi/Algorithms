#include <vector>
#include <memory>

struct NpyArray
{
    NpyArray(const std::vector<size_t> &_shape, size_t _word_size, bool _fortran_order) : shape(_shape), word_size(_word_size), fortran_order(_fortran_order)
    {
        num_vals = 1;
        for (size_t i = 0; i < shape.size(); i++)
            num_vals *= shape[i];
        data_holder = std::shared_ptr<std::vector<char>>(new std::vector<char>(num_vals * word_size));
    }

    NpyArray() : shape(0), word_size(0), fortran_order(0), num_vals(0) {}

    template <typename T>
    T *data()
    {
        return reinterpret_cast<T *>(&(*data_holder)[0]);
    }

    template <typename T>
    const T *data() const
    {
        return reinterpret_cast<T *>(&(*data_holder)[0]);
    }

    template <typename T>
    std::vector<T> as_vec() const
    {
        const T *p = data<T>();
        return std::vector<T>(p, p + num_vals);
    }

    size_t num_bytes() const
    {
        return data_holder->size();
    }

    std::shared_ptr<std::vector<char>> data_holder;
    std::vector<size_t> shape;
    size_t word_size;
    bool fortran_order;
    size_t num_vals;
};