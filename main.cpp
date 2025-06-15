#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "index.h"
#include "renderer_windows.h"
#include "dirt.h"

int main() {
    dirt dirt_block; // Create an instance of the dirt block
    const block* block_query = get_block_by_id(1);
    if (block_query) {
        std::cout << "Block ID: " << block_query->get_block_data().block_id << std::endl;
    } else {
        std::cout << "Block not found!" << std::endl;
    }
    return 0;
}