//
// Created by Azusa_Ke on 25-6-16.
//

#ifndef AIR_H
#define AIR_H

#include "block.h"

class __declspec(dllexport) air : public block {
    public:
    air();
    void on_block_placed() override;
    static const int ID = 4;
};
REGISTER_BLOCK(air, air::ID);



#endif //AIR_H
