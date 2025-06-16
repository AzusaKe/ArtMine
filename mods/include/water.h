//
// Created by Azusa_Ke on 25-6-16.
//

#ifndef WATER_H
#define WATER_H

#include "../../block_core/include/block.h"

class __declspec(dllexport) water : public block {
    public:
    water();
    void on_block_placed() override;
    static const int ID = 3;
};
REGISTER_BLOCK(water, water::ID);

#endif //WATER_H
