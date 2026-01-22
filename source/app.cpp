#include <iostream>
#include "app.h"

int main(){
    try {
        auto[filemane, key_from, key_to] = parse_arguments(arg_count, arg_vars);
        matrix_t matr = load_matrix(filename);
        validate(matr, key_from, key_to);
        auto [weight, route] = compute_route(matr, key_from, key_to);
        components_t components = compute_components(matr);
        print_shortest_route(weight, route);
        print_components(components);
    }
    catch(const std::exception& except){
        sdt::cerr <<"ERROR:" << e.what() << '\n';
    }
    
}