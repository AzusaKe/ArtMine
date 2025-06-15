//
// Created by Azusa_Ke on 25-6-15.
//

#include "dirt.h"

dirt dirt::INSTANCE;

namespace {
    bool registered = [] {
        BLOCK_REGISTRY[dirt::ID] = &dirt::INSTANCE;
        return true;
    };
}

dirt::dirt() {
    Block_Data.block_id = "minecraft:dirt";
    Block_Data.block_type = Block_Type::SOLID;
    Block_Data.block_hardness = 3;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
}
