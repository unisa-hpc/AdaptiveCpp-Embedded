#!/bin/bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=/home/lcrisci/workspace/librert/AdaptiveCpp-Embedded/install/ -DCMAKE_BUILD_TYPE=Debug 
cmake --build build -- -j 
$PWD/../install/bin/acpp -O0 -g sycl_buffer.cc -o sycl_buffer
