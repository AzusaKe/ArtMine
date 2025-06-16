//
// Created by Azusa_Ke on 25-6-15.
//

#include "mod_loader.h"

#include <iostream>

void load_mods() {
    std::filesystem::path mods_dir = "mods"; // Directory containing mod DLLs
    if (!std::filesystem::exists(mods_dir) || !std::filesystem::is_directory(mods_dir)) {
        return;
    }

    for (const auto &entry: std::filesystem::directory_iterator(mods_dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".dll") {
            HMODULE module = LoadLibraryA(entry.path().string().c_str());
            if (module) {
                loaded_modules.push_back(module);
            }
        }
    }
}

void unload_mods() {
    for (const auto& module : loaded_modules) {
        FreeLibrary(module);
        std::cout << "Unloaded module: " << module << std::endl;
    }
}


