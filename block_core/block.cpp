//
// Created by Azusa_Ke on 25-6-15.
//

#include "block.h"

// 注册表函数
std::unordered_map<int,block*>& block_registry() {
    static std::unordered_map<int, block*> registry;
    return registry;
}

// 获取方块信息的函数实现
block* get_block_by_id(int id) {
    auto it = block_registry().find(id);
    return it != block_registry().end() ? it->second : nullptr;
}

// 方块注册器实现
block_registrar::block_registrar(int id, block *b) {
    block_registry()[id] = b;
}