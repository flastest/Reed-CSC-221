#include "cities.hh"
#include <cmath>

std::istream & operator>>(std::istream & is, Cities& city){
    Cities::permutation_t city_order = city.get_permutation();
    for (int i : city_order){
        is >> city_order[i].first >> city_order[i].second;
    }
    return is;
}

std::ostream & operator<<(std::ostream & os, Cities& city){
    Cities::permutation_t city_order = city.get_permutation();
    for (int i : city_order){
        os << city_order[i].first << " " << city_order[i].second << "\n";
    }
    return os;
}

double Cities::path_between(coord_t t1, coord_t t2) const{
    int difference_first = (t1.first - t2.first);
    int difference_second = (t1.second - t2.second);
    return sqrt((pow(difference_first, 2) + pow(difference_second, 2)));
}

double Cities::total_path_distance(const permutation_t& ordering) const{
    double total;
    for (int i = 0; i < order_of_cities.size() - 1; i++){
        total += path_between(order_of_cities[i], order_of_cities[i+1]);
    }
    total += path_between(order_of_cities[0], order_of_cities[order_of_cities.size()]); //no viable conversion from 'const value_type'(aka 'const int') to 'coord_t' (aka 'pair<int, int>')
    return total;
}

Cities::Cities Cities::reorder(const permutation_t& ordering) const{
    
}