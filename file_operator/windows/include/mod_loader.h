//
// Created by Azusa_Ke on 25-6-15.
//

#ifndef MOD_LOADER_H
#define MOD_LOADER_H

#include <filesystem>
#include <windows.h>
#include <vector>

void load_mods();

inline std::vector<HMODULE> loaded_modules;

#endif //MOD_LOADER_H
