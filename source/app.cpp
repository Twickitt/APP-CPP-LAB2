#include <iostream>
#include <map>
#include <stdexcept>
#include "app.h"


using namespace std::string_literals;

node_name_t string_to_node_name(const std::string& str){
    std::istringstream in(str);
    node_name_t result;

    if (!(in >> result) || !in.eof()){
        throw std::runtime_error("Invalid node:"s + str);

    }

    if (result < 0){
        throw std::runtime_error("Node index must be positive:"s + str);
    }

    return result;
}

std::tuple<std::string, node_name_t, node_name_t> parse_args(int argc, char* argv[]) {
    if (argc != 7){
        throw std::runtime_error("Invalid number of arguments");
    }

    std::map<std::string, std::string> args = {
            {"--file", ""}, {"--from", ""}, {"--to", ""}
    };

    for (size_t i = 1; i < argc; i += 2){
        std::string key = argv[i];
        auto it = args.find(key);

        if (it == args.end()){
            throw std::runtime_error("Invalid argument:"s + key);
        }
        if (!(it->second.empty())){
            throw std::runtime_error("Duplicated argument:"s + key);
        }
        if (i + 1 >= argc){
            throw std::runtime_error("Missing value for argument:"s + key);
        }

        it->second = argv[i + 1];
    }
    for (const auto& [key, value] : args){
        if (value.empty()){
            throw std::runtime_error("Missing required argument:"s + key);
        }
    }

    return std::make_tuple(args["--file"], string_to_node_name(args["--from"]), string_to_node_name(args["--to"]));
}