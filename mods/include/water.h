//
// Created by Azusa_Ke on 25-6-16.
//

#ifndef WATER_H
#define WATER_H

#include "block.h"

class water : public block {
    public:
    water();
    void on_block_placed() override;
    static const int ID = 3;
    static const std::string block_id;
    std::string get_block_id() { return block_id; }
};
REGISTER_BLOCK(water,water::block_id, water::ID);

#endif //WATER_H
