#include "Histogram.h"

Histogram::Histogram(const Histogram& other)
    : _count { other._count } {
}

Histogram::Histogram() {
}

void Histogram::print() const {
    for (const auto& val : _count)
    { std::cout << val << ", "; }
    std::cout << std::endl;
}

void Histogram::analyze(const std::string& input) {
    for (const auto& chara : input)
    { _count[chara - 'a'] += 1; }
}