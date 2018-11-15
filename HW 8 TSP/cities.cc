#include "cities.hh"
#include <cmath>
#include <random>
#include <algorithm>
#include <iterator>

std::istream & operator>>(std::istream & is, Cities& city){
    int x;
    int y;
    std::vector<Cities::coord_t> list;
    while (is>>x){
        Cities::coord_t pair;
        pair.first = x;
        is >> y;
        pair.second = y;
        list.push_back(pair);
    }
    city.cities_ = list;
    return is;
}

std::ostream & operator<<(std::ostream & os, Cities& city){
    int x;
    int y;
    std::vector<Cities::coord_t> list;
    list = city.cities_;
    Cities::coord_t pair;
    for (int i = 0; i < list.size(); i ++){
        pair = list[i];
        x = pair.first;
        y = pair.second;
        os<<x;
        os<<y;
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
    return nullptr;
}

permutation_t Cities::random_permutation(unsigned len){
    std::std::vector<int> v(len);
    for (int i = 0; i < len; i ++) {
        vector[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(),v.end(),g);
    return reorder(&v);
}