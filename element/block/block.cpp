//
// Created by Azusa_Ke on 25-6-15.
//

#include "block.h"

#include <iostream>

block_registry BLOCK_REGISTRY;

const block* get_block_by_id(int id) {
    auto it = BLOCK_REGISTRY.find(id);
    return (it != BLOCK_REGISTRY.end()) ? it->second : nullptr;
}

block::block() {
    Block_Data.block_id = "unknown";
    Block_Data.block_type = Block_Type::AIR;
    Block_Data.block_hardness = 0;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
    std::cout << "block::block()" << std::endl;
}
