/**
 This is free and unencumbered software released into the public domain.

 See the included UNLICENSE file, or http://unlicense.org/
 */

#include "wfind.hpp"

/* Private method */
bool wfind::contentMatch(fs::path filename, std::string regexr)
{
    std::ifstream inp(filename.string(), std::ios::in | std::ios::binary);
    std::regex expr(regexr);
    if (inp.is_open())
    {
        std::string content;
        while (std::getline(inp, content))
        {
            if (std::regex_search(content, expr))
                return true;
        }
        inp.close();
    }
    return false;
}

/* Public methods */
std::vector<fs::directory_entry> wfind::searchDirectory(std::string regexr)
{
    try
    {
        std::regex expr(regexr);
    }
    catch (const std::regex_error &e)
    {
        throw e;
    }

    std::vector<fs::directory_entry> result;
    for (const auto &file : fs::recursive_directory_iterator(curWorkingDir))
    {
        if (contentMatch(file, regexr))
            result.push_back(file);
    }
    return result;
}

bool wfind::changeDirectory(fs::path path)
{
    if (!fs::exists(path) || !fs::is_directory(fs::status(path)))
        return false;
    this->curWorkingDir = path;
    return true;
}