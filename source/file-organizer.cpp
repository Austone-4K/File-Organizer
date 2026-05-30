#include <iostream>
#include <filesystem>
#include "utilities.hpp"
namespace fs = std::filesystem;

int main() {
    system("cls");

    bool stop = false;
    while (!stop) {
        std::string raw_dir_path;
        
        std::cout << "Enter \";EXIT\" to close the program" << std::endl;
        std::cout << "What directory should be re-organized?" << std::endl;
        std::cout << "Path -> ";

        std::getline(std::cin, raw_dir_path);

        if (raw_dir_path == ";EXIT") {
            std::cout << "Exiting..." << std::endl;
            stop = true;
            continue;
        }

        remove_quotes_from_raw_path_if_there_are(raw_dir_path);
        
        fs::path dir_path(raw_dir_path);

        if (!fs::exists(dir_path)) {
            std::cout << "Directory not found\n";
            continue;
        }
        else if (!fs::is_directory(dir_path)) {
            std::cout << "The path is not a directory\n";
            continue;
        }

        std::vector<std::pair<std::string, std::string>> collections =
        {
            {".xlsx", "Excel file"},
            {".txt", "Text"},
            {".exe", "Programs"},
            {".docx", "Word Docs"},
            {".pdf", "PDF File"},
            {".zip", "Zip File"},
            {".jpg", "Photos"},
            {".jpeg", "Photos"},
            {".png", "Photos"},
            {".bmp", "Photos"},
            {".tiff", "Photos"},
            {".webp", "Photos"},
            {".raw", "Raw Photos"},
            {".heif", "Photos"},
            {".heic", "Photos"},
            {".gif", "Gifs"},
            {".mp4", "Videos"},
            {".mkv", "Videos"},
            {".avi", "Videos"},
            {".mov", "Videos"},
            {".wmv", "Videos"},
            {".webm", "Videos"},
            {".flv", "Videos"},
            {".mxf", "Videos"},
            {".mp3", "Music and Audio"},
            {".aac", "Music and Audio"},
            {".m4a", "Music and Audio"},
            {".ogg", "Music and Audio"},
            {".opus", "Music and Audio"},
            {".wma", "Music and Audio"},
            {".flac", "Music and Audio"},
            {".alac", "Music and Audio"},
            {".wav", "Music and Audio"},
            {".aiff", "Music and Audio"},
            {".aif", "Music and Audio"},
            {".ape", "Music and Audio"},
            {".dsf", "Music and Audio"},
            {".dff", "Music and Audio"}
        };
        
        bool recursive = false;
        std::string be_recursive;

        std::cout << "Even the sub directories have to be re-organized?" << std::endl;
        std::cout << "yes/no -> ";
        
        get_yes_or_no(be_recursive);

        if (be_recursive == "yes") {
            recursive = true;
        }

        iterate_to_organize(dir_path, collections, recursive);

        std::string to_continue;
        std::cout << "Would you continue to use the program?" << std::endl;
        std::cout << "yes / no -> ";
        
        get_yes_or_no(to_continue);

        if (to_continue == "no") {
            std::cout << "Exiting..." << std::endl;
            stop = true;
        }
    }
}