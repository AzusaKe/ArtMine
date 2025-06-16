//
// Created by Azusa_Ke on 25-6-16.
//

#ifndef MOD_LOADER_H
#define MOD_LOADER_H

#include <filesystem>
#include <dlfcn.h>
#include <vector>

void load_mods();

void unload_mods();

inline std::vector<void*> loaded_modules;

#endif //MOD_LOADER_H
