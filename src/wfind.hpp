#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>

#if __cplusplus < 201703L
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
    wfind(std::string path = fs::current_path())
    {
        changeDirectory(path);
    }
    std::vector<fs::directory_entry> searchDirectory(std::string keyword);
    bool changeDirectory(fs::path path)
    {
        if (!fs::exists(path) && !fs::is_directory(path))
            return false;
        this->curWorkingDir = path;
        return true;
    }
    const fs::path &currentDirectory() { return curWorkingDir; }
};
