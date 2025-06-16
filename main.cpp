#include <iostream>
#include "blocks.h"
#include <windows.h>

int main() {
    HMODULE hModule = LoadLibraryA("libwater.dll");
    if (hModule) {
        std::cout << "Water module loaded successfully." << std::endl;
        auto init_water_mod = reinterpret_cast<void(*)()>(GetProcAddress(hModule, "init_water_mod"));
        if (init_water_mod) {
            init_water_mod();
            std::cout << "Water mod initialized." << std::endl;
        } else {
            std::cerr << "Failed to find init_water_mod function." << std::endl;
        }
    } else {
        std::cerr << "Failed to load water module." << std::endl;
    }
    block* b = get_block_by_id(1);
    if (b) {
        std::cout << "ID 1 is: " << b->get_block_data().block_id << std::endl;
    }
    b = get_block_by_id(2);
    if (b) {
        std::cout << "ID 2 is: " << b->get_block_data().block_id << std::endl;
    } else {
        std::cout << "Block with ID 2 not found." << std::endl;
    }
    b = get_block_by_id(3);
    if (b) {
        std::cout << "ID 3 is: " << b->get_block_data().block_id << std::endl;
    } else {
        std::cout << "Block with ID 3 not found." << std::endl;
    }
    return 0;
}