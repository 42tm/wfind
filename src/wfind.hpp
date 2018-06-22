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
    wfind(std::string path = fs::current_path()) : curWorkingDir(path) {}
    std::vector<fs::directory_entry> searchDirectory(std::string keyword);
    void changeDirectory(fs::path path) { this->curWorkingDir = path; }
    const fs::path &currentDirectory() { return curWorkingDir; }
};
