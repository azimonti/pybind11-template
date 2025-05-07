#include <iomanip> // For std::fixed and std::setprecision if needed for float/double output
#include <iostream>
#include <vector> // Required for std::vector
#include "example.h"

int main()
{
    std::cout << "--- C++ Main Demonstration ---" << std::endl;

    // Test Example class
    std::cout << "\nTesting Example class:" << std::endl;
    Example ex("C++ User");
    ex.greet();
    std::cout << "Current name: " << ex.getName() << std::endl;
    ex.setName("Direct C++ User");
    ex.greet();

    // Test VectorWriter<float>
    std::cout << "\nTesting VectorWriter<float>:" << std::endl;
    VectorWriter<float> vw_float;
    std::cout << "Float vector elements from getVector(): ";
    std::vector<float> float_vec = vw_float.getVector();
    for (size_t i = 0; i < float_vec.size(); ++i)
    {
        std::cout << float_vec[i] << (i == float_vec.size() - 1 ? "" : ", ");
    }
    std::cout << std::endl;
    vw_float.printVector();

    // Test VectorWriter<double>
    std::cout << "\nTesting VectorWriter<double>:" << std::endl;
    VectorWriter<double> vw_double;
    std::cout << "Double vector elements from getVector(): ";
    std::vector<double> double_vec = vw_double.getVector();
    for (size_t i = 0; i < double_vec.size(); ++i)
    {
        std::cout << double_vec[i] << (i == double_vec.size() - 1 ? "" : ", ");
    }
    std::cout << std::endl;
    vw_double.printVector();

    std::cout << "\n--- C++ Main Demonstration End ---" << std::endl;
    return 0;
}
