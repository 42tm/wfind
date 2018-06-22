#include <iostream>
#include <filesystem>
#include "src/wfind.hpp"

int main(int argc, char const *argv[])
{
    if ((argc == 1) || (argc == 2 && (argv[1] == std::string("-h") || argv[1] == std::string("--help"))))
    {
        std::cout << "wfind - Find files whose contents match the given search regular expression"
                  << std::endl << std::endl
                  << argv[0] << " [regex] (directory)" << std::endl << std::endl
                  << "  regex     : regex used to find in files" << std::endl
                  << "  directory : (Optional) look up location" << std::endl;
        return 0;
    }

    std::string keyword = std::string(argv[1]);

    wfind sif;
    if (argc > 2)
        if (!sif.changeDirectory(fs::path(std::string(argv[2]))))
        {
            std::cout << "Directory does not exist." << std::endl;
            return 1;
        }

    std::cout << "Looking up directory: " << sif.currentDirectory() << std::endl;
    std::cout << "Regex: \"" << keyword << "\"" << std::endl;

    std::vector<fs::directory_entry> result;
    try
    {
        result = sif.searchDirectory(keyword);
    }
    catch (std::regex_error e)
    {
        std::cout << "Regex error." << std::endl;
    }

    for (auto &&iter : result)
        std::cout << iter << std::endl;
    if (result.empty())
    {
        std::cout << "No matches found." << std::endl;
    }
    else
    {
        std::cout << result.size() << " file(s) found." << std::endl;
    }

    return 0;
}
