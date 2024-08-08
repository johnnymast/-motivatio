#include <iostream>


#include <fstream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <utility>
#include <iostream>
#include <random>

class Quote {
public:
    Quote(std::string quote, std::string author): quote(std::move(quote)), author(std::move(author)) {};

    std::string GetQuote() { return quote; }
    std::string GetAuthor() { return author; }
private:
    std::string quote;
    std::string author;
};
class Quotes {
public:
    explicit Quotes(const std::string& file_path) {
        std::ifstream i(file_path);
        i >> m_quotes;
    }

    Quote getQuote(size_t index) {
        if (index < m_quotes["data"].size()) {
            auto entry = m_quotes["data"][index];
            return {entry["quote"], entry["author"]};
        }
    }

    Quote getRandomQuote() {
        // Use the system's random device
        std::random_device rd;

        // Seed the generator
        std::mt19937 gen(rd());

        // Create a uniform distribution between 0 and the total number of quotes (exclusive)
        std::uniform_int_distribution<> dis(0, m_quotes["data"].size() - 1);

        // Generate a random index
        size_t random_index = dis(gen);

        return getQuote(random_index);
    }

    [[nodiscard]] size_t size() const {
        return m_quotes["data"].size();
    }


private:
    nlohmann::json m_quotes;
};

int main() {
    Quotes quotes("../data.json");

    Quote q = quotes.getRandomQuote();
    std::cout << q.GetQuote() << " -- " << q.GetAuthor() << std::endl;
    return 0;
}
