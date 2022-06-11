#include "parser.hpp"
#include <algorithm>
std::string Parser::getip(std::string body)
{
    std::string s = "ip\":";
    auto it = std::search(std::begin(body), std::end(body), std::begin(s), std::end(s));
    s.clear();
    for (it += 5; it < body.end() - 2; it++)
    {
        s += *it;
    }
    return s;
}
std::string Parser::getCordinates(std::string body)
{
    std::string s = "latitude";
    std::string e = "metro_code";
    auto it = std::search(std::begin(body), std::end(body), std::begin(s), std::end(s));
    auto ite = std::search(std::begin(body), std::end(body), std::begin(e), std::end(e));

    s.clear();
    for (it; it < ite; it++)
    {
        s += *it;
    }
    return s;
}