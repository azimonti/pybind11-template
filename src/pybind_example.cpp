/************************/
/*  pybind_example.cpp  */
/*     Version 1.0      */
/*      2023/05/05      */
/************************/

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "example.h"

namespace py = pybind11;

PYBIND11_MODULE(example_module, m)
{
    m.doc() = "pybind11 example plugin"; // Optional module docstring

    py::class_<Example>(m, "Example")
        .def(py::init<const std::string&>())
        .def("greet", &Example::greet)
        .def("getName", &Example::getName)
        .def("setName", &Example::setName)
        .def_property("name", &Example::getName, &Example::setName); // Expose as property

    // Binding for VectorWriter<float>
    py::class_<VectorWriter<float>>(m, "VectorWriterFloat")
        .def(py::init<>())
        .def("getVector", &VectorWriter<float>::getVector)
        .def("printVector", &VectorWriter<float>::printVector)
        .def("writeToMemoryArray", [](const VectorWriter<float>& self, py::array_t<float> output_array) {
        py::buffer_info buf_info = output_array.request();
        if (buf_info.ndim != 1) { throw std::runtime_error("Output array must be 1-dimensional."); }
        float* ptr  = static_cast<float*>(buf_info.ptr);
        size_t size = static_cast<size_t>(buf_info.shape[0]);
        self.writeToMemoryArray(ptr, size);
    }, py::arg("output_array").noconvert(), "Copies the vector content to a pre-allocated NumPy array.");

    // Binding for VectorWriter<double>
    py::class_<VectorWriter<double>>(m, "VectorWriterDouble")
        .def(py::init<>())
        .def("getVector", &VectorWriter<double>::getVector)
        .def("printVector", &VectorWriter<double>::printVector)
        .def("writeToMemoryArray", [](const VectorWriter<double>& self, py::array_t<double> output_array) {
        py::buffer_info buf_info = output_array.request();
        if (buf_info.ndim != 1) { throw std::runtime_error("Output array must be 1-dimensional."); }
        double* ptr = static_cast<double*>(buf_info.ptr);
        size_t size = static_cast<size_t>(buf_info.shape[0]);
        self.writeToMemoryArray(ptr, size);
    }, py::arg("output_array").noconvert(), "Copies the vector content to a pre-allocated NumPy array.");
}
