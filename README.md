# Python Bindings Template

A boilerplate to use C++ code in Python using pybind11.

## Requirements

- Git
- CMake
- clang
- Python

## Getting Started

To get started with the template:

1. Clone the repository:
   ```
   git clone https://github.com/azimonti/pybind11-template
   ```
2. Navigate to the repository directory:
   ```
   cd pybind11-template
   ```

3. [Optional] If used with ma-libs, initialize and update the submodules:
  ```
  git submodule update --init --recursive
  ```

Further update of the submodule can be done with the command:
  ```
  git submodule update --remote
  ```

4. Install required Python dependencies in a virtual environment and activate it:
   ```
   ./create_env.sh
   source "venv/bin/activate" #venv/Scripts/activate on MINGW
   ```

5. Compile the libraries
  ```
  ./build_libs_standalone.sh
  # ./build_ma_libs.sh # if compiled along with ma-libs
  ```

  If any error or missing dependencies for `ma-libs` please look at the instructions [here](https://github.com/azimonti/ma-libs)


6. Run the program
  ```
  python main_standalone.py
  ./build/Release/main(.exe) # library is linkedin to a c++ binary
  # if compiled along with ma-libs
  # python main_ma_libs.py
  # ./externals/ma-libs/Release/main(.exe)
  ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions or want to get in touch regarding the project, please open an issue or contact the repository maintainers directly through GitHub.
