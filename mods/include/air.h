//
// Created by Azusa_Ke on 25-6-16.
//

#ifndef AIR_H
#define AIR_H

#include "block.h"

class air : public block {
    public:
    air();
    void on_block_placed() override;
    static const int ID = 4;
    static const std::string block_id;
    std::string get_block_id() {  printf("air");return block_id;}
};
REGISTER_BLOCK(air,air::block_id, air::ID);



#endif //AIR_H
