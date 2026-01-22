#include <iostream>
#include <map>
#include <stdexcept>
#include "app.h"


int main(int arg_count, char* arg_vars[]){
    try {
    auto[filemane, key_from, key_to] = parse_args(arg_count, arg_vars);
    //     matrix_t matr = load_matrix(filename);
    //     validate(matr, key_from, key_to);
    //     auto [weight, route] = compute_route(matr, key_from, key_to);
    //     components_t components = compute_components(matr);
    //     print_shortest_route(weight, route);
    //     print_components(components);
    }
    catch(const std::exception& except){
        std::cerr <<"ERROR:" << except.what() << '\n';
    }
    return 0;
}