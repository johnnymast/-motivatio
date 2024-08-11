#include "include/cli.h"
#include <cxxopts.hpp>

/**
 * @brief Constructs a Cli object with the given command line arguments.
 *
 * The Cli constructor initializes an instance of cxxopts::Options with the program name and
 * a brief description of what the program does. It then assigns the count of command line arguments
 * to the member variable argc and assigns the command line arguments to the member variable argv.
 *
 * @param c The count of command line arguments.
 * @param agv An array of command line arguments.
 */
Cli::Cli(int c, char** agv): opts(cxxopts::Options(agv[0], "Motivatio, display a random quote.")) {
    argc = c;
    argv.assign(agv, agv + c);
}


/**
 * @brief Handles the user input and returns the selected style.
 *
 * The handle method parses the command line arguments provided by the user
 * using the cxxopts library. It looks for the "style" argument and retrieves
 * its value if it is specified. If the "help" argument is present, it prints
 * the usage information and returns 0. Otherwise, it returns the default style
 * or the style specified by the user.
 *
 * @return The selected style.
 */
int Cli::handle() {
    int style = Style::DEFAULT;

    opts.add_options()
           ("s,style", "Name of the user", cxxopts::value<int>())
           ("h,help", "Print usage");

    char** argv_tmp = argv.data();
    auto result = opts.parse(argc, argv_tmp);

    if (result.count("help")) {
        std::cout << opts.help() << std::endl;
        return 0;
    }

    if (result.count("style")) {
        style = result["style"].as<int>();
    }

    return style;
}
