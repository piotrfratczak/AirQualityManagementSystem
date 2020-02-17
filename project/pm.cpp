#include <pybind11/pybind11.h>
#include "include/standard.hpp"
#include "include/airSystem.hpp"


PYBIND11_MODULE( testyx, m ){
  m.doc() = "pybind11 example";
  pybind11::class_<AirSystem>(m, "system" )
    .def(pybind11::init())
    .def("parseSensor", &AirSystem::parseSensor)
    .def("parseAttribute", &AirSystem::parseAttribute)
    .def("parseData", &AirSystem::parseData)
    .def("menu", &AirSystem::menu);
}