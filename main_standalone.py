'''
/**********************/
/* main_standalone.py */
/*    Version 1.0     */
/*     2025/05/07     */
/**********************/
'''
import numpy as np
import os
import sys

cwd = os.getcwd()
build_dir = os.path.join(cwd, "./build")
if "DEBUG" in os.environ:
    build_path = os.path.join(build_dir, "Debug")
else:
    build_path = os.path.join(build_dir, "Release")
sys.path.append(os.path.realpath(build_path))

# Import the compiled module.
# The name 'example_module' must match the name given in PYBIND11_MODULE.
try:
    import example_module
except ImportError as e:
    print(f"Error: {e}")

def run_example_tests():
    print("--- Testing Example class ---")
    ex = example_module.Example("World")
    ex.greet()  # Should print "Hello, World!"
    print(f"Initial name: {ex.getName()}")
    ex.setName("Python User")
    print(f"Updated name: {ex.name}") # Using property
    ex.greet() # Should print "Hello, Python User!"

    print("\n--- Testing VectorWriterFloat ---")
    vw_float = example_module.VectorWriterFloat()
    print(f"Float vector: {vw_float.getVector()}")
    vw_float.printVector() # Should print "Vector elements: 1, 2, 3, 4"

    print("\n--- Testing VectorWriterDouble ---")
    vw_double = example_module.VectorWriterDouble()
    print(f"Double vector: {vw_double.getVector()}")
    vw_double.printVector() # Should print "Vector elements: 1, 2, 3, 4"

    print("\n--- Testing writeToMemoryArray (Float) ---")
    float_array_output = np.zeros(4, dtype=np.float32)
    vw_float.writeToMemoryArray(float_array_output)
    print(f"Content of float_array_output after writeToMemoryArray: {float_array_output}")

    print("\n--- Testing writeToMemoryArray (Double) ---")
    double_array_output = np.zeros(4, dtype=np.float64)
    vw_double.writeToMemoryArray(double_array_output)
    print(f"Content of double_array_output after writeToMemoryArray: {double_array_output}")


if __name__ == "__main__":
    run_example_tests()
