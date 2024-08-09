#ifndef PASER_H
#define PASER_H

#include <fstream>
#include <nlohmann/json.hpp>

class Parser {
public:
    static nlohmann::json ParseFile(const std::string& file_path);
};

#endif //PASER_H
