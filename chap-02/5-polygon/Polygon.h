#pragma once

#include <ostream>
#include <utility>
#include <vector>

using vertex = std::pair<int, int>;

class Polygon
{
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& poly);

private:
    std::vector<vertex> _verticies;

public:
    const vertex& get_vertex(size_t idx) const;
    void          add_vertex(const int& x, const int& y);
};
