# File Organizer

A command-line C++ application designed to automatically clean up messy folders. The program scans all files within a specified directory and moves them into categorized subfolders based on their file extensions.

## Features

* **Automated Organization:** Group files into logical categories (Photos, Videos, Documents, Music, etc.).
* **Recursive Support:** Option to organize not only the root directory but also all nested subfolders.
* **Input Sanitization:** Automatically handles file paths copied from Windows that include quotation marks (`"`).
* **Interactive CLI:** Step-by-step user guidance for path input and execution preferences.

# Supported Categories

The application recognizes a wide range of extensions, including:

* **Documents:** `.txt`, `.docx`, `.pdf`, `.xlsx`
* **Images:** `.jpg`, `.png`, `.gif`, `.webp`, `.raw`, `.heic`
* **Video:** `.mp4`, `.mkv`, `.avi`, `.mov`, `.webm`
* **Audio:** `.mp3`, `.wav`, `.flac`, `.aac`, `.ogg`
* **Archives & Executables:** `.zip`, `.exe`

# Technical Specifications

* **Language:** C++17 or higher.
* **Libraries:** Heavy reliance on the standard `<filesystem>` library (introduced in C++17).
* **Target OS:** Primarily developed for Windows environments (utilizes `system("cls")` for console clearing).

# Compilation

You can compile the project using any compiler that supports C++17 or higher (such as GCC, Clang, or MSVC) or you can use Cmake.

Example using `g++`:

```bash
g++ -std=c++17 source/file-organizer.cpp -o file-organizer

```

Example using `Cmake`:

```bash
cmake -B build
cmake --build build
```

# Usage Instruction

1. Run the executable application.
2. Enter the absolute path of the directory you want to clean up (e.g., `C:\Users\Name\Downloads`).
3. Choose whether to proceed recursively (`yes` or `no`).
4. The application will dynamically create the target subfolders (if they do not exist) and safely move the files.
5. You can choose to process another folder or exit by typing `;EXIT`.

# ⚠️ Notes & Warnings

* Ensure the running application has appropriate write permissions for the selected directory.
* The program physically moves files on your drive using `fs::rename`. Please make a backup beforehand if you are processing sensitive data.
