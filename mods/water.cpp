//
// Created by Azusa_Ke on 25-6-16.
//

#include "include/water.h"

#include <iostream>

const std::string water::block_id = "minecraft:water";

water::water() {
    Block_Data.block_type = Block_Type::LIQUID;
    Block_Data.block_hardness = -1;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
}

void water::on_block_placed() {
    // 水块被放置时的逻辑
    std::cout << "Water block placed!" << std::endl;
}
