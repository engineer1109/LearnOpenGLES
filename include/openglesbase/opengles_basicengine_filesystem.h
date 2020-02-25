#ifndef OPENGLES_BASICENGINE_FILESYSTEM_H
#define OPENGLES_BASICENGINE_FILESYSTEM_H
#include "opengles_basicengine_help.h"
class FS {
public:
    static std::string getAssetPath(std::string p) {
#if defined(__GNUC__) && __GNUC__ > 7
        using namespace std::filesystem;
#else
        using namespace std::experimental::filesystem;
#endif
        path pa = path(std::string("../data/" + p).c_str()); // for vs2015 compatibility
        path pb = path(std::string(PROJECT_ABSOLUTE_PATH + ("/data/" + p)).c_str());
        if (exists(pa)) {
            return std::string("../data/" + p);
        }
        else if (exists(pb)) {
            return std::string(PROJECT_ABSOLUTE_PATH + ("/data/" + p));
        }
        else {
            std::cout << "Error!Could not find this file:" << p << std::endl;
            exit(1);
        }
    }
};
#endif // OPENGLES_BASICENGINE_FILESYSTEM_H
