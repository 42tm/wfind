/**
 This is free and unencumbered software released into the public domain.

 See the included UNLICENSE file, or http://unlicense.org/
 */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

#if (__cplusplus < 201703L || __GNUC__ < 8)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

class wfind
{
  private:
    fs::path curWorkingDir;
    bool contentMatch(fs::path filename, std::string keyword);

  public:
    wfind(fs::path path = fs::current_path()) { changeDirectory(path); }
    std::vector<fs::directory_entry> searchDirectory(std::string keyword);
    bool changeDirectory(fs::path path)
    {
        if (!fs::exists(path) || !fs::is_directory(fs::status(path)))
            return false;
        this->curWorkingDir = path;
        return true;
    }
    const fs::path &currentDirectory() { return curWorkingDir; }
};
