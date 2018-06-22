#include <iostream>
#include <filesystem>
#include "src/wfind.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << argv[0] << " [regex] (directory)" << std::endl
                  << std::endl
                  << "regex     : regex used to find in files" << std::endl
                  << "directory : (Optional) look up location" << std::endl;
        return 0;
    }
    std::string keyword = std::string(argv[1]);

    wfind sif;
    if (argc > 2)
        sif.changeDirectory(fs::path(std::string(argv[2])));

    std::cout << "Cwd: " << sif.currentDirectory() << std::endl;
    std::cout << "Keyword: \"" << keyword << "\"" << std::endl;

    auto result = sif.searchDirectory(keyword);
    for (auto &&iter : result)
        std::cout << iter << std::endl;
    return 0;
}
