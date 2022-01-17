#include "Polygon.h"

std::ostream& operator<<(std::ostream& stream, const Polygon& poly) {
    for (const auto& point : poly._verticies)
    { stream << "(" << point.first << "," << point.second << ") "; }
    return stream;
}

const vertex& Polygon::get_vertex(size_t idx) const {
    return _verticies[idx];
}

void Polygon::add_vertex(const int& x, const int& y) {
    _verticies.emplace_back(x, y);
}