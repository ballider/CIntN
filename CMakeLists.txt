cmake_minimum_required(VERSION 2.8)

project(CIntN)

set(CIntN_src main.cpp CIntN.cpp AutoTest.cpp)
set(CIntN_hdr head.hpp CIntN.hpp AutoTest.hpp)

add_executable(${PROJECT_NAME} ${CIntN_src} ${CIntN_hdr})