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
};
REGISTER_BLOCK(water,water::Block_Data.block_id, water::ID);

#endif //WATER_H
