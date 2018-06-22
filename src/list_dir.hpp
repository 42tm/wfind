#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

class searchInFiles
{
  private:
    fs::path curWorkingDir;
    bool contentMatch(fs::path filename, std::string keyword);

  public:
    searchInFiles(std::string path = fs::current_path()) : curWorkingDir(path) {}
    std::vector<fs::directory_entry> searchDirectory(std::string keyword);
    void changeDirectory(fs::path path) { this->curWorkingDir = path; }
    const fs::path &currentDirectory() { return curWorkingDir; }
};
