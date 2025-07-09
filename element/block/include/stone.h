//
// Created by Azusa_Ke on 25-6-16.
//

#ifndef STONE_H
#define STONE_H

#include "block.h"

class stone final : public block {
public:
    stone();
    void on_block_placed() override;
    static const int ID = 2;
};
REGISTER_BLOCK(stone,stone::Block_Data.block_id, stone::ID)

#endif //STONE_H
