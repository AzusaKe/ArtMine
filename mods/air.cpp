//
// Created by Azusa_Ke on 25-6-16.
//

#include "include/air.h"

#include <iostream>

const std::string air::block_id = "minecraft:air";

air::air() {
    Block_Data.block_type = Block_Type::AIR;
    Block_Data.block_hardness = -1;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
}

void air::on_block_placed() {
    // 空气块被放置时的逻辑
    std::cout << "Air block placed!" << std::endl;
}
