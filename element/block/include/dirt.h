//
// Created by Azusa_Ke on 25-6-15.
//

#ifndef DIRT_H
#define DIRT_H

#include "block.h"

class dirt final : public block {
public:
    dirt();
    void on_block_placed() override;
    static const int ID = 1;
};

#endif // DIRT_H