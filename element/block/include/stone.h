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
    static const std::string block_id;
    std::string get_block_id() { return block_id; }
};
REGISTER_BLOCK(stone,stone::block_id, stone::ID)

#endif //STONE_H
