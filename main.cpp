#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "index.h"
#include "renderer_windows.h"
#include "dirt.h"

void initialize_blocks() {
    // 这个函数的作用是触发静态变量的初始化
    // 在实际运行中，这个函数可能什么都不需要做
    // 只需要确保它被调用即可
    volatile int dummy = 0;
    (void)dummy;
}

int main() {
    dirt dirt_block; // 创建一个 dirt 实例
    dirt_block.on_block_placed();
    return 0;
}