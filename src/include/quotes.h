#ifndef QUOTES_H
#define QUOTES_H

#include <optional>
#include <vector>

#include "parser.h"
#include "quote.h"

class Quotes {
public:
    Quotes();

    std::optional<Quote> getQuote(size_t index);
    std::optional<Quote> getRandomQuote();

private:
    Parser parser = Parser();
    std::vector<Quote> quotes;
};

#endif
