#ifndef _EXAMPLE_H_24351BDFE1814A9F88DCA2FBF9A75202_
#define _EXAMPLE_H_24351BDFE1814A9F88DCA2FBF9A75202_

/******************/
/*   example.h    */
/*  Version 1.0   */
/*   2023/05/07   */
/******************/

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// Standard class for basic input/output
class Example
{
  public:
    Example(const std::string& name);
    void greet();
    std::string getName() const;
    void setName(const std::string& name);

  private:
    std::string name_;
};

// Template class to write a vector of 4 elements
template <typename T> class VectorWriter
{
  public:
    VectorWriter();
    std::vector<T> getVector() const;
    void printVector() const;
    void writeToMemoryArray(T* out_array, size_t size) const; // Renamed method

  private:
    std::vector<T> data_;
};

// Explicit template instantiations if needed by some compilers,
// or can be handled in the .cpp file.
// extern template class VectorWriter<float>;
// extern template class VectorWriter<double>;

#endif
