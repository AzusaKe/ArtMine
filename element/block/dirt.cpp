//
// Created by Azusa_Ke on 25-6-15.
//

#include "dirt.h"

#include <iostream>

const int dirt::ID;

dirt dirt::INSTANCE;

namespace {
    // 使用函数局部静态变量来确保正确的初始化顺序
    bool register_dirt() {
        BLOCK_REGISTRY[dirt::ID] = &dirt::INSTANCE;
        return true;
    }

    bool registered = register_dirt();
}

dirt::dirt() {
    Block_Data.block_id = "minecraft:dirt";
    Block_Data.block_type = Block_Type::SOLID;
    Block_Data.block_hardness = 3;
    Block_Data.block_light_level = 0;
    Block_Data.block_direction = Block_Direction::UP;
    Block_Data.block_r_level = R_Level::R_LEVEL_0;
}

void dirt::on_block_placed() {
    std::cout << "Dirt block placed!" << std::endl;
}