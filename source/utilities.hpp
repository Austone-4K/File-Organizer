#pragma once

#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

void get_yes_or_no(std::string& where_to_store) {
    std::getline(std::cin, where_to_store);

    while (where_to_store != "yes" && where_to_store != "no") {
        std::cout << "Enter yes or no -> ";
        std::getline(std::cin, where_to_store);
    }
}

void remove_quotes_from_raw_path_if_there_are(std::string& raw_path) {
    if (raw_path == "\"" || raw_path == "\"\"" || raw_path.empty()) {
        return;
    }
    
    if (raw_path.at(0) == '\"') {
        raw_path.erase(raw_path.begin());
    }

    if (raw_path.back() == '\"') {
        raw_path.erase(raw_path.end() - 1);
    }
}

void create_dir_if_not_exists(const fs::path& path) {
    try {
        if (!fs::exists(path)) {
            fs::create_directory(path);
        }
    }
    catch (const std::string& error) {
        std::cout << "ERROR IN \"create_dir_if_not_exists\": " << error << std::endl;
    }
}

void iterate_to_organize(const fs::path& dir_path, const std::vector<std::pair<std::string, std::string>>& collections, const bool& recursive) {
    try {
        if (recursive) {
            for (auto& entry : fs::recursive_directory_iterator(dir_path)) {
                std::string entry_ext = entry.path().extension().string();
    
                for (const auto& pair : collections) {
                    if (entry_ext == pair.first) {
                        create_dir_if_not_exists(dir_path / pair.second);
                        fs::rename(entry.path(), entry.path().parent_path() / pair.second / entry.path().filename());
                    }
                }
            }
        }
        else {
            for (auto& entry : fs::directory_iterator(dir_path)) {
                std::string entry_ext = entry.path().extension().string();
    
                for (const auto& pair : collections) {
                    if (entry_ext == pair.first) {
                        create_dir_if_not_exists(dir_path / pair.second);
                        fs::rename(entry.path(), entry.path().parent_path() / pair.second / entry.path().filename());
                    }
                }
            }
        }
    }
    catch (const std::string& error) {
        std::cout << "ERROR IN \"iterate_to_organize\": " << error << std::endl;
    }
}