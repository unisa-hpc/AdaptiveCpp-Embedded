#include <sycl/sycl.hpp>
#include <iostream>

int main(){
    sycl::queue q;

    std::cout << "Running on device: " << q.get_device().get_info<sycl::info::device::name>() << std::endl;

    auto* ptr = sycl::malloc_device<int>(5, q);

    int data[5];

    {
        sycl::buffer<int, 1> buf(data, sycl::range<1>(5));

    q.submit([&](sycl::handler& cgh){
        sycl::accessor acc(buf, cgh);

        cgh.parallel_for<class test>(sycl::range<1>(5), [acc](sycl::item<1> idx){
            acc[idx] = idx.get_linear_id();
        });
    });

    sycl::host_accessor acc(buf);

    }

    for(int i = 0; i < 5; i++){
        std::cout << data[i] << " ";
    }
}