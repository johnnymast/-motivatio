#ifndef PASER_H
#define PASER_H

#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

#include <nlohmann/json.hpp>
#include "quote.h"

class Parser {
public:
    std::vector<Quote> ParseFile(const std::string& file_path);
    std::vector<Quote> ParseFilesAtDirectory(const std::string& path);

private:
    std::vector<Quote> result;
};

#endif //PASER_H
