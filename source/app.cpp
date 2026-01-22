#include <iostream>
#include "app.h"

int main(){
    // try {
    //     auto[filemane, key_from, key_to] = parse_arguments(arg_count, arg_vars);
    //     matrix_t matr = load_matrix(filename);
    //     validate(matr, key_from, key_to);
    //     auto [weight, route] = compute_route(matr, key_from, key_to);
    //     components_t components = compute_components(matr);
    //     print_shortest_route(weight, route);
    //     print_components(components);
    // }
    // catch(const std::exception& except){
    //     sdt::cerr <<"ERROR:" << e.what() << '\n';
    // }
    return 0;
}


std::tuple<std::string, node_name_t, node_name_t> parse_args(int argc, char* argv[]){
    if (argc < 7)
        throw std::runtime_error("Invalid number of arguments\nUsage: graph --file <path-name> --from <node-index> --to <node-index>");

    std::string filename;
    bool has_file = false;
    bool has_from = false;
    bool has_to   = false;
    node_name_t from = 0;
    node_name_t to   = 0;
    std::unordered_set<std::string> seen;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--file") {

            if (!seen.insert(arg).second)
                throw std::runtime_error("Duplicated argument: --file");

            if (i + 1 >= argc)
                throw std::runtime_error("Missing value for --file");

            filename = argv[++i];
            has_file = true;
        }

        else if (arg == "--from") {
            
            if (!seen.insert(arg).second)
                throw std::runtime_error("Duplicated argument: --from");

            if (i + 1 >= argc)
                throw std::runtime_error("Missing value for --from");

            char* end = nullptr;
            unsigned long v = std::strtoul(argv[++i], &end, 10);
            if (*end != '\0')
                throw std::runtime_error("Invalid node: " + std::string(argv[i]));

            from = static_cast<node_name_t>(v);
            has_from = true;
        }

        else if (arg == "--to") {

            if (!seen.insert(arg).second)
                throw std::runtime_error("Duplicated argument: --to");

            if (i + 1 >= argc)
                throw std::runtime_error("Missing value for --to");

            char* end = nullptr;
            unsigned long v = std::strtoul(argv[++i], &end, 10);
            if (*end != '\0')
                throw std::runtime_error("Invalid node: " + std::string(argv[i]));

            to = static_cast<node_name_t>(v);
            has_to = true;
        }

        else 
            throw std::runtime_error("Invalid argument: " + arg + "\nUsage: graph --file <path-name> --from <node-index> --to <node-index>");
            
    }

    if (!has_file || !has_from || !has_to) {
        throw std::runtime_error(
            "Missing required arguments\n"
            "Usage: graph --file <path-name> --from <node-index> --to <node-index>"
        );
    }

    return { filename, from, to };
}