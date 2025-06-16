//
// Created by Azusa_Ke on 25-6-15.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <unordered_map>

enum class Block_Type { AIR = 0, SOLID = 1, LIQUID = 2 };
enum class Block_Direction { UP = 0, DOWN = 1, NORTH = 2, SOUTH = 3, EAST = 4, WEST = 5 };
enum class R_Level {
    R_LEVEL_0 = 0, R_LEVEL_1 = 1, R_LEVEL_2 = 2, R_LEVEL_3 = 3, R_LEVEL_4 = 4, R_LEVEL_5 = 5,
    R_LEVEL_6 = 6, R_LEVEL_7 = 7, R_LEVEL_8 = 8, R_LEVEL_9 = 9, R_LEVEL_10 = 10,
    R_LEVEL_11 = 11, R_LEVEL_12 = 12, R_LEVEL_13 = 13, R_LEVEL_14 = 14, R_LEVEL_15 = 15
};

struct block_data {
    std::string block_id;
    Block_Type block_type;
    int block_hardness;
    int block_light_level;
    Block_Direction block_direction;
    R_Level block_r_level;
};

class block {
public:
    virtual ~block() = default;

    block_data Block_Data;
    block() = default;
    [[nodiscard]] const block_data& get_block_data() const {
        return Block_Data;
    }
    virtual void on_block_placed() = 0;
    static const int ID;
};

std::unordered_map<int,block*>& block_registry();

block* get_block_by_id(int id);

class block_registrar {
public:
    block_registrar(int id, block* b) {
        block_registry()[id] = b;
    }
};

#define REGISTER_BLOCK(classname,id) \
    static classname classname##_instance; \
    static block_registrar registrar_##classname(id, &classname##_instance);

#endif // BLOCK_H