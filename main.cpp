#include <iostream>
#include "blocks.h"
#include <windows.h>
#include "mod_loader.h"

int main(){
    load_mods();
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
    b = get_block_by_id(4);
    if (b) {
        std::cout << "ID 4 is: " << b->get_block_data().block_id << std::endl;
    } else {
        std::cout << "Block with ID 4 not found." << std::endl;
    }
    for (const auto& module : loaded_modules) {
        FreeLibrary(module);
        std::cout << "Unloaded module: " << module << std::endl;
    }
    return 0;
}