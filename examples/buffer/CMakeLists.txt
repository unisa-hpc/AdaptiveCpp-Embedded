add_executable(sycl_buffer sycl_buffer.cc)
add_sycl_to_target(TARGET sycl_buffer SOURCES sycl_buffer.cpp)
