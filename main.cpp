#define SPACE " "

#include <iostream>
#include <string>
#include <cxxopts.hpp>
#include <termcolor/termcolor.hpp>
#include <iomanip>

#include "src/include/quotes.h"
#include "src/include/quote.h"
#include "src/include/cli.h"
#include "src/include/styles.h"



int main(int argc, char *argv[]) {
    Cli cli(argc, argv);

    Quotes quotes;
    std::optional<Quote> quote = quotes.getRandomQuote();

    std::string str_quote = quote.value().GetQuote();
    std::string str_author = quote.value().GetAuthor();

    int style = cli.handle();

    if (quote.has_value()) {
        switch (style) {
            case Style::AUTHOR_AT_END:
                std::cout << str_quote << " Author: " << termcolor::yellow << str_author << termcolor::reset << std::endl;
                break;
            case Style::AUTHOR_AT_END_COLORED:
                std::cout << str_quote << " " << termcolor::yellow << str_author << termcolor::reset << std::endl;
            break;
            case AUTHOR_AT_NEW_LINE_COLORED:
                std::cout << str_quote  << std::endl;
                std::cout << "Author: " << termcolor::yellow << str_author << termcolor::reset << std::endl;
                break;
            default:
                std::cout << str_quote << " -- " << str_author << std::endl;
                break;
        }

        std::string sentence =
                "Stop letting people who do so little for you control so much of your mind and emotions.";
    }

    return 0;
}
