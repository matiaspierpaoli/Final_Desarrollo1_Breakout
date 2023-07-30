#include "URLOpener.h"

namespace BreakoutGame
{
    void URLOpener::OpenURL(std::string url) {
        // Use platform-specific commands to open the URL
#ifdef _WIN32
    // Windows
        std::string command = "start ";
        command += url;
#elif __APPLE__
    // macOS
        std::string command = "open ";
        command += url;
#else
    // Linux and other platforms
        std::string command = "xdg-open ";
        command += url;
#endif

        // Use std::system to execute the command
        std::system(command.c_str());
    }
}