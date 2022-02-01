#pragma once

#include "line.hpp"

class LineSegment : public Line
{
public:
    using Line::Line;

    void filter_points_inside(PointContainer& points) const {
        for (auto iter = points.begin(); iter != points.end();)
        {
            if (iter->is_between(first, last))
            { ++iter; }
            else
            { iter = points.erase(iter); }
        }
    }

    PointContainer intersect(const Shape& shape) const override {
        PointContainer candidates = shape.intersect((Line) * this);
        filter_points_inside(candidates);
        return candidates;
    }

    PointContainer intersect(const Line& ln) const override {
        PointContainer candidates = ln.intersect(*this);
        filter_points_inside(candidates);
        return candidates;
    }

    std::ostream& print(std::ostream& os) const { return os << "Segment"; }

    ~LineSegment() = default;
};
