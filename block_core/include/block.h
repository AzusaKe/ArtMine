//
// Created by Azusa_Ke on 25-6-15.
//

#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <unordered_map>

/* WIN导出宏 */

#ifdef _WIN32
  #ifdef BLOCK_CORE_EXPORTS
    #define BLOCK_CORE_API __declspec(dllexport)
  #else
    #define BLOCK_CORE_API __declspec(dllimport)
  #endif
#else
  #define BLOCK_CORE_API
#endif

// 方块类型 AIR-空气 SOLID-固体 LIQUID-液体
enum class Block_Type { AIR = 0, SOLID = 1, LIQUID = 2 };
// 方块朝向 上下东南西北
enum class Block_Direction { UP = 0, DOWN = 1, NORTH = 2, SOUTH = 3, EAST = 4, WEST = 5 };
// 红石能量等级 0-15
enum class R_Level {
    R_LEVEL_0 = 0, R_LEVEL_1 = 1, R_LEVEL_2 = 2, R_LEVEL_3 = 3, R_LEVEL_4 = 4, R_LEVEL_5 = 5,
    R_LEVEL_6 = 6, R_LEVEL_7 = 7, R_LEVEL_8 = 8, R_LEVEL_9 = 9, R_LEVEL_10 = 10,
    R_LEVEL_11 = 11, R_LEVEL_12 = 12, R_LEVEL_13 = 13, R_LEVEL_14 = 14, R_LEVEL_15 = 15
};

// 结构体：方块数据
// 包含：字符串：方块id
//      方块类型
//      整型：  方块硬度
//      整型：  方块默认亮度
//      方块默认朝向
//      方块红石能量等级
struct block_data {
    std::string block_id;
    Block_Type block_type;
    int block_hardness;
    int block_light_level;
    Block_Direction block_direction;
    R_Level block_r_level;
};

// 基类： 方块
// 包含：数据成员：方块数据
//              方块数字ID
//      成员函数：方块放置-on_block_placed
//              获取方块数据-get_block_data      
class BLOCK_CORE_API block {
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

// 方块注册表
std::unordered_map<int,block*>& block_registry();

// 用于方块注册的函数-get_block_by_id-参数：整型：ID-返回：方块指针
block* BLOCK_CORE_API get_block_by_id(int id);

// 方块注册器
class BLOCK_CORE_API block_registrar {
public:
    block_registrar(int id, block* b) ;
};

// 方块注册宏-REGISTER_BLOCK-参数：类名 ID-无返回值
#define REGISTER_BLOCK(classname,id) \
    static classname classname##_instance; \
    static block_registrar registrar_##classname(id, &classname##_instance);

#endif // BLOCK_H