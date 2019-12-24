#ifndef OPENGLES_BASICENGINE_FILESYSTEM_H
#define OPENGLES_BASICENGINE_FILESYSTEM_H
#include "opengles_basicengine_help.h"
class FS{
public:
    static std::string getAssetPath(std::string p){
        using namespace std::experimental::filesystem;
        path pa=path(std::string("../data/"+p).c_str());   //for vs2015 compatibility
        path pb=path(std::string(PROJECT_ABSOLUTE_PATH+("/data/"+p)).c_str());
        if(exists(pa)){
            return std::string("../data/"+p);
        }
        else if(exists(pb)){
            return std::string(PROJECT_ABSOLUTE_PATH+("/data/"+p));
        }
        else {
            std::cout<<"Error!Could not find this file:"<<p<<std::endl;
            exit(1);
        }
    }
};
#endif // OPENGLES_BASICENGINE_FILESYSTEM_H
