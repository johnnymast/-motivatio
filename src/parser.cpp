#include "include/parser.h"

/**
 * @brief Parse the JSON file and return the JSON data.
 *
 * This method reads the JSON file located at the given file_path and parses it using nlohmann::json library.
 * The resulting JSON data is returned.
 *
 * @param file_path The path to the JSON file to be parsed.
 *
 * @return The nlohmann::json object containing the parsed JSON data.
 */
nlohmann::json Parser::ParseFile(const std::string& file_path) {
    nlohmann::json m_quotes;

    std::ifstream i(file_path);
             i >> m_quotes;

    return m_quotes;
}
