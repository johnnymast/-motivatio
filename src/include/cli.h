#ifndef CLI_H
#define CLI_H

#include <cxxopts.hpp>
#include "styles.h"

class Cli {
public:
    Cli(int c, char** agv);
    int handle();

private:
    cxxopts::Options opts;
    std::vector<char*> argv;
    int argc;
};



#endif //CLI_H
