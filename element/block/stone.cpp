//
// Created by Azusa_Ke on 25-6-16.
//

#include "stone.h"

#include <iostream>

stone::stone() {
    Block_Data.block_id = "minecraft:stone";
    Block_Data.block_type = Block_Type::SOLID;
    Block_Data.block_hardness = 10;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
}

void stone::on_block_placed() {
    std::cout << "Stone block placed!" << std::endl;
}