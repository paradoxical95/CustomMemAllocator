#ifndef CUSTOM_CUDA_MEMORY_H
#define CUSTOM_CUDA_MEMORY_H

#include <cuda_runtime.h>
#include <iostream>

// Custom CUDA Memory Management Functions
class CustomCudaMemory {
public:
    // Allocates memory on the device
    static void* allocate(size_t size) {
        void* d_ptr;
        cudaError_t err = cudaMalloc(&d_ptr, size);
        if (err != cudaSuccess) {
            std::cerr << "CUDA Error in allocation: " << cudaGetErrorString(err) << std::endl;
            return nullptr;
        }
        return d_ptr;
    }

    // Frees memory on the device
    static void free(void* d_ptr) {
        if (d_ptr) {
            cudaError_t err = cudaFree(d_ptr);
            if (err != cudaSuccess) {
                std::cerr << "CUDA Error in free: " << cudaGetErrorString(err) << std::endl;
            }
        }
    }
};

#endif // CUSTOM_CUDA_MEMORY_H
