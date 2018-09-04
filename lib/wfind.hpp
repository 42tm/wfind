/**
 This is free and unencumbered software released into the public domain.

 See the included UNLICENSE file, or http://unlicense.org/
 */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

#if __has_include(<filesystem>) && __cplusplus >= 201703L
#include <filesystem>
#elif __has_include(<experimental/filesystem>)
#include <experimental/filesystem>
#warning "Using <experimental/filesystem>"
#else
#error "Missing <filesystem>"
#endif

#ifdef __cpp_lib_filesystem
namespace fs = std::filesystem;
#elif defined(__cpp_lib_experimental_filesystem)
namespace fs = std::experimental::filesystem;
#else
#error "Missing std::filesystem"
#endif

class wfind
{
  private:
    /* Variables */
    fs::path curWorkingDir;

    /* Methods */
    bool contentMatch(fs::path filename, std::string keyword);

  public:
    /* Constructors */
    wfind(fs::path path = fs::current_path()) { changeDirectory(path); }

    /* Methods */
    const fs::path &currentDirectory() { return curWorkingDir; }
    std::vector<fs::directory_entry> searchDirectory(std::string keyword);
    bool changeDirectory(fs::path path);
};
