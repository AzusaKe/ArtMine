#include <iostream>
#include "blocks.h"
#include <windows.h>

int main() {
    HMODULE hModule = LoadLibraryA("libwater.dll");
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