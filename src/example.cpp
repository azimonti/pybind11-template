/******************/
/*   example.cpp  */
/*  Version 1.0   */
/*   2023/05/07   */
/******************/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include "example.h"

// Implementation for Example class
Example::Example(const std::string& name) : name_(name) {}

void Example::greet()
{
    std::cout << "Hello, " << name_ << "!" << std::endl;
}

std::string Example::getName() const
{
    return name_;
}

void Example::setName(const std::string& name)
{
    name_ = name;
}

// Implementation for VectorWriter template class
template <typename T> VectorWriter<T>::VectorWriter()
{
    // Initialize data_ with {1, 2, 3, 4}
    // Using direct initialization for simplicity
    data_.push_back(static_cast<T>(1));
    data_.push_back(static_cast<T>(2));
    data_.push_back(static_cast<T>(3));
    data_.push_back(static_cast<T>(4));
}

template <typename T> std::vector<T> VectorWriter<T>::getVector() const
{
    return data_;
}

template <typename T> void VectorWriter<T>::printVector() const
{
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < data_.size(); ++i) { std::cout << data_[i] << (i == data_.size() - 1 ? "" : ", "); }
    std::cout << std::endl;
}

template <typename T> void VectorWriter<T>::writeToMemoryArray(T* out_array, size_t size) const
{
    if (size < data_.size()) { throw std::runtime_error("Output array size is smaller than data size."); }
    std::copy(data_.begin(), data_.end(), out_array);
}

// Explicit template instantiations
template class VectorWriter<float>;
template class VectorWriter<double>;
