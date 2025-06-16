#include <iostream>
#include "blocks.h"
#include <windows.h>

int main() {
    HMODULE hModule = LoadLibrary("libwater.dll");
    if (!hModule) {
        std::cerr << "Failed to load the library." << std::endl;
        return 1;
    }else {
        std::cout << "Library loaded successfully." << std::endl;

    }
    block* b = get_block_by_id(1);
    if (b) {
        std::cout << "ID 1 is: " << b->get_block_data().block_id << std::endl;
        b->on_block_placed();
    }
    b = get_block_by_id(2);
    if (b) {
        std::cout << "ID 2 is: " << b->get_block_data().block_id << std::endl;
        b->on_block_placed();
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