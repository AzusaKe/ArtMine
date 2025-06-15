//
// Created by Azusa_Ke on 25-6-15.
//

#include "block.h"

std::unordered_map<int,block*>& block_registry() {
    static std::unordered_map<int, block*> registry;
    return registry;
}

block* get_block_by_id(int id) {
    auto it = block_registry().find(id);
    return it != block_registry().end() ? it->second : nullptr;
}