/*
    자료형에게 가명 붙여주기 type aliases
*/
#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    typedef double distance_t;
    //std::int8_t i(97);

    double      my_distance;
    distance_t  home2work;
    distance_t  home2school;

    typedef std::vector<std::pair<std::string, int>> pairlist_t;

    using pairlist_t = std::vector<std::pair<std::string, int>>;

    //std::vector<std::pair<std::string, int>> pairlist;
    pairlist_t pairlist1;

    return 0;
}