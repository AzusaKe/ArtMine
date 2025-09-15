//
// Created by Azusa_Ke on 25-6-15.
//

#include "block.h"

const std::string block::block_id;

// 注册表函数
std::unordered_map<int,block*>& block_registry() {
    static std::unordered_map<int, block*> registry;
    return registry;
}

std::unordered_map<std::string, block*>& block_registry_id() {
    static std::unordered_map<std::string, block*> registry_id;
    return registry_id;
}

// 获取方块信息的函数实现
block* get_block_by_id(int id) {
    auto it = block_registry().find(id);
    return it != block_registry().end() ? it->second : nullptr;
}

block* get_block_by_id(std::string block_id)
{
    auto it = block_registry_id().find(block_id);
    return it != block_registry_id().end() ? it->second : nullptr;
}

// 方块注册器实现
block_registrar::block_registrar(int id, block *b) {
    block_registry()[id] = b;
}

block_registrar::block_registrar(std::string block_id, block *b) {
    block_registry_id()[block_id] = b;
}