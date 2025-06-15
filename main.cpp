#include <iostream>
#include "blocks.h"

void initialize_blocks() {
    // 这个函数的作用是触发静态变量的初始化
    // 在实际运行中，这个函数可能什么都不需要做
    // 只需要确保它被调用即可
    volatile int dummy = 0;
    (void)dummy;
}

int main() {
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
    return 0;
}