# API
## `block` 类

---
### `const block* get_block_by_id(int id)`
返回一个指针指向对应`ID`的对象`block*`
用法：
```c++
const block* query_block = get_block_by_id(1);
```
---
### `const block* get_block_by_id(const std::string& block_id)`
返回一个指针指向对应`block_id`的对象`block*`
用法：
```c++
const block* query_block = get_block_by_id("minecraft:dirt");
```

---
### `int get_block_id() const`
返回当前方块的`ID`用法：
```c++
std::string block_id = query_block->get_block_id();
```

---
### `const block_data& get_block_data() const`
返回一个`block_data`的引用，包含了当前方块的数据

数据结构如下：
```c++
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
```
于是可以获取当前`id`的方块数据：
```c++
const block* query_block = get_block_by_id(1);
std::cout<< query_block->get_block_data().block_id << std::endl;
```
输出为
```id
minecraft:dirt
```
---

