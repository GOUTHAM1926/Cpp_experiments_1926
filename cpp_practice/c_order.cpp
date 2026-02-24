#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

/**
 * @brief Utility function to calculate the linear offset (index) from 3D coordinates (i, j, k).
 * @param i, j, k The coordinates.
 * @param D1, D2 The sizes of the middle and innermost dimensions.
 */
int calculate_linear_index(int i, int j, int k, int D1, int D2) {
    // C-Order Strides: Stride for i = D1*D2, Stride for j = D2, Stride for k = 1
    const int stride0 = D1 * D2; 
    const int stride1 = D2;
    const int stride2 = 1;
    
    return i * stride0 + j * stride1 + k * stride2;
}

// ----------------------------------------------------------------------------------
// 1. OPTIMAL ACCESS: C-ORDER SEQUENTIAL (k loop fastest)
// ----------------------------------------------------------------------------------
void print_tensor_c_order(const std::vector<int>& data, int D0, int D1, int D2) {
    std::cout << "\n--- 1. OPTIMAL: C-Order (Sequential Access) ---" << std::endl;
    // Note the loop order: i -> j -> k
    for (int i = 0; i < D0; ++i) { // Slowest change (Planes)
        for (int j = 0; j < D1; ++j) { // Medium change (Rows)
            std::cout << "  Row [" << i << ", " << j << ", *]: ";
            
            // K is the innermost loop: this accesses memory contiguously (0, 1, 2, 3...)
            for (int k = 0; k < D2; ++k) { // Fastest change (Columns)
                
                int linear_index = calculate_linear_index(i, j, k, D1, D2);
                
                // When k changes from 0 to 1, the linear_index only increases by 1.
                // This means we are guaranteed to hit the CPU cache.
                int value = data[linear_index];
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
}

// ----------------------------------------------------------------------------------
// 2. SUB-OPTIMAL ACCESS: NON-SEQUENTIAL (i loop fastest)
// ----------------------------------------------------------------------------------
void print_tensor_non_sequential(const std::vector<int>& data, int D0, int D1, int D2) {
    std::cout << "\n--- 2. SUB-OPTIMAL: Non-Sequential Access ---" << std::endl;
    
    // Note the loop order: k -> j -> i
    // This flips the conventional C-order access.
    for (int k = 0; k < D2; ++k) { // Columns (Outermost loop)
        for (int j = 0; j < D1; ++j) { // Rows (Middle loop)
            std::cout << "  Slice [*, " << j << ", " << k << "]: ";
            
            // I is the innermost loop: this changes the index by D1*D2 (12) each step!
            for (int i = 0; i < D0; ++i) { // Fastest change in THIS loop
                
                int linear_index = calculate_linear_index(i, j, k, D1, D2);
                
                // When i changes from 0 to 1, the linear_index jumps by 12.
                // E.g., Accesses indices 0, then 12, then 24... missing the cache!
                int value = data[linear_index];
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
}


int main() {
    // Tensor Shape: [2 Planes, 3 Rows, 4 Columns] -> Total 24 elements
    const int D0 = 2; // i
    const int D1 = 3; // j
    const int D2 = 4; // k
    const int total_elements = D0 * D1 * D2;

    // 1. Initialize the flat memory block (THE RAM STORAGE)
    std::vector<int> tensor_data(total_elements);
    // Fill the memory sequentially: 0, 1, 2, 3, 4, 5, ... 23
    std::iota(tensor_data.begin(), tensor_data.end(), 0); 

    std::cout << "Raw 1D Memory (The Physical Data): ";
    for (int val : tensor_data) {
        std::cout << val << " ";
    }
    std::cout << "\n\n";

    // Call the two access methods for comparison
    print_tensor_c_order(tensor_data, D0, D1, D2);
    print_tensor_non_sequential(tensor_data, D0, D1, D2);
    
    return 0;
}
