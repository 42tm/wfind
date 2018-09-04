/**
 This is free and unencumbered software released into the public domain.

 See the included UNLICENSE file, or http://unlicense.org/
 */

#include <iostream>
#include "lib/wfind.hpp"

int main(int argc, char const *argv[])
{
    std::cout
        << "wfind - Find files whose contents match the given search regular expression" << std::endl;

    std::cout << "  version: ";
#if defined(_WFIND_VERSION)
    std::cout << _WFIND_VERSION << std::endl;
#else
    std::cout << "custom build" << std::endl;
#endif

    std::cout << "  built with ";
// Check compiler's name & version
#if defined(__clang__)
    std::cout << "Clang " << __clang_version__ << std::endl;
#elif defined(__GNUC__)
    std::cout
        << "GCC " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__;

    #if defined(__MINGW64__)
    std::cout << " (MinGW-w64 64bit)";
    #elif defined(__MINGW32__)
    std::cout << " (MinGW/MinGW-w64 32bit)";
    #endif

    #ifdef __CYGWIN__
    std::cout << " (Cygwin)";
    #endif

    std::cout << std::endl;
#elif defined(_MSC_VER)
    std::cout
        << "MS Visual C++ " << _MSC_FULL_VER << std::endl;
#else
    std::cout << "unknown C++ compiler" << std::endl;
#endif

    if ((argc == 1) || (argc == 2 && (argv[1] == std::string("-h") || argv[1] == std::string("--help"))))
    {
        std::cout
            << std::endl
            << "Usage: " << argv[0] << " [regex] [directory]" << std::endl
            << std::endl
            << "  regex     : Regular expression used to find in files" << std::endl
            << "  directory : (Optional) Directory for look up" << std::endl;
        return 0;
    }

    std::string keyword = std::string(argv[1]);

    wfind sif;
    if (argc > 2)
        if (!sif.changeDirectory(fs::path(std::string(argv[2]))))
        {
            std::cout << "wfind: directory does not exist." << std::endl;
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
        std::cout << "wfind: regex error" << std::endl;
    }

    for (auto &&iter : result)
        std::cout << iter << std::endl;
    if (result.empty())
        std::cout << "wfind: no files found." << std::endl;
    else
        std::cout << "wfind: " << result.size() << " file(s) found." << std::endl;

    return 0;
}
