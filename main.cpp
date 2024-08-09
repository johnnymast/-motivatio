#include <iostream>
#include <cxxopts.hpp>

#include "src/include/quotes.h"
#include "src/include/quote.h"

int main(int argc, char* argv[]) {

    // cxxopts::Options options(argv[0], "A brief description of what the program does");
    //
    // options.add_options()
    //   ("n,name", "Name of the user", cxxopts::value<std::string>())
    //   ("a,age", "Age of the user", cxxopts::value<int>())
    //   ("h,help", "Print usage")
    // ;
    //
    // auto result = options.parse(argc, argv);
    //
    // if (result.count("help"))
    // {
    //     std::cout << options.help() << std::endl;
    //     return 0;
    // }
    //
    // if(!result.count("name") || !result.count("kage"))
    // {
    //     std::cout << "ERROR: name and age must be specified\n";
    //     std::cout << options.help() << std::endl;
    //     return 1;
    // }
    //
    // std::string name = result["name"].as<std::string>();
    // int age = result["age"].as<int>();
    //
    // std::cout << "Name: " << name << "\nAge: " << age << std::endl;


    Quotes quotes;
    std::optional<Quote> quote = quotes.getRandomQuote();

    if (quote.has_value()) {
        std::cout << quote.value().GetQuote() << " -- " << quote.value().GetAuthor() << std::endl;
    }
    return 0;
}
