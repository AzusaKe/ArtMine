//
// Created by Azusa_Ke on 25-6-16.
//

#include "water.h"

#include <iostream>

water::water() {
    Block_Data.block_id = "minecraft:water";
    Block_Data.block_type = Block_Type::LIQUID;
    Block_Data.block_hardness = 0;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
}

void water::on_block_placed() {
    std::cout << "Water block placed!" << std::endl;
}
