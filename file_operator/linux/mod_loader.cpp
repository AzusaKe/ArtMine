//
// Created by Azusa_Ke on 25-6-16.
//

#include "mod_loader.h"

#include <iostream>

void load_mods() {
    // 加载模组时从运行的可执行文件本体存在的目录寻找mods文件夹，在里面加载目录
    std::filesystem::path exe_path = std::filesystem::canonical("/proc/self/exe").parent_path();
    std::filesystem::path mods_dir = exe_path / "mods"; // Directory containing mod shared libraries
    if (!std::filesystem::exists(mods_dir) || !std::filesystem::is_directory(mods_dir)) {
        std::cerr << "Mods directory not found: " << mods_dir << std::endl;
        return;
    }

    for (const auto &entry : std::filesystem::directory_iterator(mods_dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            void* module = dlopen(entry.path().string().c_str(), RTLD_LAZY);
            if (module) {
                loaded_modules.push_back(module);
            }
        }
    }
}

void unload_mods() {
    for (const auto& module : loaded_modules) {
        dlclose(module);
        std::cout << "Unloaded module: " << module << std::endl;
    }
    loaded_modules.clear();
}